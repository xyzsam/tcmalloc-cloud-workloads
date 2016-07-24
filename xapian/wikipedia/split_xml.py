#!/usr/bin/env python
#
# Split the Wikipedia XML dump into separate HTML pages.

import argparse
import fnmatch
import os
import math

NUM_DBS = 64
OUTPUT_DB = "/dev/shm/wiki/wiki_html_pages_split"

def split_xml_dump(xmlfile):
  """ The original function to split an XML dump. """
  start_tag = "<page>"
  end_tag = "</page>"
  with open(xmlfile, "r") as f:
    curr_f = None
    curr_f_name = 0
    print curr_f_name
    for line in f:
      if start_tag in line:
        curr_f = open("%d.html" % curr_f_name, "w")
        curr_f.write(line)
      elif end_tag in line:
        curr_f.write(line)
        curr_f.close()
        curr_f = None
        curr_f_name += 1
        if curr_f_name % 10000 == 0:
          print curr_f_name
      elif not curr_f is None:
        curr_f.write(line)

def count_files(extracted_dir):
  count = 0
  for root, dirnames, filenames in os.walk(extracted_dir):
    for filename in fnmatch.filter(filenames, "*.html"):
      count += 1
  return count

def split_file(filename, starting_file_no, curr_output_dir):
  """ Splits the current merged file and returns the number of the ending file. """
  start_tag = "<doc"
  end_tag = "</doc>"
  curr_f_no = starting_file_no
  curr_f = None
  with open(filename, "r") as f:
    for line in f:
      if start_tag in line:
        curr_f = open(os.path.join(curr_output_dir, "%d.html" % curr_f_no), "w")
        curr_f.write(line)
      elif end_tag in line:
        curr_f.write(line)
        curr_f.close()
        curr_f = None
        curr_f_no += 1
      elif not curr_f is None:
        curr_f.write(line)
  return curr_f_no

def split_all_files(extracted_dir):
  num_html_files = count_files(extracted_dir)
  num_dirs = len(os.listdir(extracted_dir))
  collapse_factor = num_dirs / NUM_DBS
  num_files_per_dir = int(math.ceil(float(num_html_files)/NUM_DBS))

  print "Total number of existing files: ", num_html_files
  print "Total number of existing directories:", num_dirs

  curr_input_file_no = 0  # Number of the file to be split
  curr_split_file_no = 0  # Number of the last file produced.
  curr_output_dir_no = 0  # Number of the output directory.
  curr_output_dir = os.path.join(OUTPUT_DB, "%d" % curr_output_dir_no)
  if not os.path.exists(curr_output_dir):
    os.mkdir(curr_output_dir)
  print "Processing output dir %d" % curr_output_dir_no

  for root, dirnames, filenames in os.walk(extracted_dir):
    for filename in fnmatch.filter(filenames, "*.html"):
      curr_split_file_no = split_file(
          os.path.join(root, filename), curr_split_file_no, curr_output_dir)
      curr_input_file_no += 1
      if curr_input_file_no >= num_files_per_dir:
        print "Processed %d input files and produced %d output files." % (
            curr_input_file_no, curr_split_file_no)
        curr_input_file_no = 0
        curr_split_file_no = 0
        curr_output_dir_no += 1
        curr_output_dir = os.path.join(OUTPUT_DB, "%d" % curr_output_dir_no)
        if not os.path.exists(curr_output_dir):
          os.mkdir(curr_output_dir)
        print "Processing output dir %d" % curr_output_dir_no

def main():
  parser = argparse.ArgumentParser()
  # parser.add_argument("xmlfile")
  parser.add_argument("extracted_dir")
  args = parser.parse_args()

  full_path = os.path.abspath(args.extracted_dir)
  if not "dev/shm" in full_path:
    print ("Splitting an XML file into thousands of smaller files will "
           "take an eternity on NFS!!!! Strongly recommend using /dev/shm "
           "instead.")


  split_all_files(args.extracted_dir)


if __name__ == "__main__":
  main()
