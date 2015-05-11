import os
import sys

trace = sys.argv[1]
blt = os.environ['BLT']
counter = 0
avgdir = os.path.join(blt, 'stats/averages')
if not os.path.exists(avgdir):
  os.mkdir(avgdir)
for outf in sorted(os.listdir(os.path.join(blt, 'stats'))):
    if outf.startswith(trace):
      read_fd = open(os.path.join(blt, 'stats', outf), 'r')
      write_fd = open(os.path.join(blt, 'stats/averages', 'avg_'+outf), 'w')
      write_fd.write('Length, Bugs Caught, Average Time to Catch Bugs, Average Paths to Catch Bugs\n')
      bugs = 0
      time = 0
      paths = 0
      for line in read_fd.read().splitlines():
        data = [x.strip() for x in line.split(',')]
        if int(data[0]) == counter:
          if int(data[1]):
            bugs += int(data[1])
            time += float(data[2])
            paths += int(data[3])
        elif int(data[0]) == counter + 1:
          if bugs:
            write_fd.write(str(counter) + ','
              + str(bugs) + ','
              + str(time/bugs) + ','
              + str(paths/bugs) + '\n')
          else:
            write_fd.write(str(counter) + ',0,0,0\n')
          counter += 1
          bugs = int(data[1])
          time = float(data[2])
          paths = int(data[3])
        else:
          print "Fail"
      counter = 0

