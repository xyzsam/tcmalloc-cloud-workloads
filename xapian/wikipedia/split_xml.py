#!/usr/bin/env python
#
# Split the Wikipedia XML dump into separate HTML pages.

import argparse

def split_file(xmlfile):
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


def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("xmlfile")
  args = parser.parse_args()

  if not "dev/shm" in args.xmlfile:
    print ("Splitting an XML file into thousands of smaller files will "
           "take an eternity on NFS!!!! Strongly recommend using /dev/shm "
           "instead.")
  split_file(args.xmlfile)


if __name__ == "__main__":
  main()
