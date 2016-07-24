#!/usr/bin/env python
#
# Index the Wikipedia dump with multiple runs of parallel jobs.

import argparse
import datetime
import os
import shlex
import shutil
import subprocess
import sys

# Wrap sys.stdout in an unbuffered object. This way we can monitor progress even through nohup.
class Unbuffered(object):
   def __init__(self, stream):
       self.stream = stream
   def write(self, data):
       self.stream.write(data)
       self.stream.flush()
   def __getattr__(self, attr):
       return getattr(self.stream, attr)
sys.stdout = Unbuffered(sys.stdout)

PERM_DB_DIR = "/group/vlsiarch/samxi/xapian_dbs/wiki_html_pages_2"
TEMP_DB_DIR = "/dev/shm/wiki/temp_dbs"
CMD = "%(omindex)s --db %(db)s --url / %(webpath)s"
OMINDEX_PATH = "/group/vlsiarch/samxi/active_projects/malloc/tcmalloc-cloud-workloads/xapian/xapian-omega-1.4.0/build/omindex"

DRY_RUN = False

class Slice(object):
  """ A process indexing one slice of the complete database. """
  def __init__(self, wiki_dir, slice_name):
    self.slice_name = slice_name
    self.wiki_dir = os.path.abspath(os.path.join(wiki_dir, slice_name))
    self.db_dir = os.path.abspath(os.path.join(TEMP_DB_DIR, slice_name, "default"))
    self.child = None
    self.retcode = 0
    self.start_time = None
    self.end_time = None

  def start(self):
    """ Start the indexing process. """
    if not os.path.exists(self.db_dir):
      os.makedirs(self.db_dir)
    cmd = CMD % {"omindex": OMINDEX_PATH,
                 "db": self.db_dir,
                 "webpath": self.wiki_dir}
    print cmd
    if not DRY_RUN:
      stdin = None
      stdout = None
      stderr = None
      cwd = os.getcwd()
      self.start_time = datetime.datetime.now()
      self.child = subprocess.Popen(shlex.split(cmd),
                                    close_fds=True,
                                    stdin=stdin,
                                    stdout=stdout,
                                    stderr=stderr,
                                    cwd=cwd)

      print "Launched child process %d on subdir %s" % (
              self.child.pid, self.slice_name)

  def mark_done(self):
    """ Add a done file to the db directory to denote this is finished. """
    if DRY_RUN:
      return

    done_file = os.path.join(self.db_dir, "done")
    if not os.path.exists(done_file):
      f = open(done_file, "w")
      f.close()

    print "Slice %s marked as done." % self.slice_name
    return

  def cleanup(self):
    """ Move the complete index to NFS for permanent storage. """
    if DRY_RUN:
      return

    perm_dir = os.path.join(PERM_DB_DIR, self.slice_name)
    if not os.path.exists(perm_dir):
      os.makedirs(perm_dir)
    shutil.move(self.db_dir, perm_dir)
    print "Moved slice %s to permanent storage." % self.slice_name

  def wait(self):
    """ Wait for the indexing to finish.

    If it finishes successfully, mark it as done and move the index. Otherwise,
    print an error message.
    """
    if not DRY_RUN:
      self.retcode = self.child.wait()
    else:
      print "DRY RUN SUCCEEDED"
      self.mark_done()
      return

    self.end_time = datetime.datetime.now()
    elapsed = self.end_time - self.start_time
    if self.retcode == 0:
      print "Slice %s with child %d COMPLETED in " % (
          self.slice_name, self.child.pid), elapsed
      self.mark_done()
      self.cleanup()
    else:
      print "Slice %s with child %d FAILED with retcode %d in " % (
          self.slice_name, self.child.pid, retcode), elapsed

class Job(object):
  """ A collection of slices that runs in parallel. """

  def __init__(self, slice_names, wiki_dir):
    self.slices = [Slice(wiki_dir, sl) for sl in slice_names]
    self.wiki_dir = wiki_dir

  def wait(self):
    for sl in self.slices:
      sl.wait()
    return

  def start(self):
    """ Start the job. """
    for sl in self.slices:
      sl.start()
    return

  def report_bad_slices(self):
    bad = []
    for sl in self.slices:
      if not sl.retcode == 0:
        bad.append(sl)
    if len(bad) > 0:
      print "WARNING: Slices %s failed to complete successfully." % ", ".join(bad)
    else:
      print "SUCCESS: All slices finished successfully."

def find_finished_slices(slices):
  finished = []
  for s in slices:
    if os.path.exists(os.path.join(TEMP_DB_DIR, s, "default", "done")):
      finished.append(s)
  return finished

def launch_indexing(wiki_dir, num_jobs):
  # Get all slices and remove the ones that are already done.
  slices = os.listdir(wiki_dir)
  finished_slices = find_finished_slices(slices)
  for sl in finished_slices:
    slices.remove(sl)

  # Divide the remaining slices by job.
  num_slices = len(slices)
  print "%d slices remaining." % num_slices
  curr_job = 0
  curr_slice_idx = 0
  slices_split = [[] for i in range(num_jobs)]
  while curr_slice_idx < num_slices:
    slices_split[curr_job].append(slices[curr_slice_idx])
    curr_job = (curr_job + 1) % num_jobs
    curr_slice_idx += 1

  jobs = [Job(slices_split[i], wiki_dir) for i in range(num_jobs)]

  # Run one job at a time.
  for job in jobs:
    job.start()
    job.wait()
    job.report_bad_slices()

def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("wiki_dir", help="Location of the split wiki dump.")
  parser.add_argument("jobs", type=int, help="Number of jobs.")
  parser.add_argument("--dry", action="store_true")
  args = parser.parse_args()

  global DRY_RUN
  DRY_RUN = bool(args.dry)

  launch_indexing(args.wiki_dir, args.jobs)

if __name__ == "__main__":
  main()
