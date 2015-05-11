import os
import sys

trace = sys.argv[1]
blt = os.environ['BLT']
counter = 1
propdir = os.path.join(blt, 'stats/prop_bugs')
if not os.path.exists(propdir):
  os.mkdir(propdir)

caught = [0 for _ in range(50)]
time = 0
paths = 0

write_fd = open(os.path.join(blt, 'stats/prop_bugs', 'prop_{0}.txt'.format(trace)), 'w')
write_fd.write('Length, Number Mutants Caught, Average Time Per Mutant, Average Paths Per Mutant\n')

def get_mutants_caught():
  global caught
  total = 0
  for mutant in caught:
    if mutant == 1:
      total += 1
  return total

# loop through all lengths
while counter < 100:
  # loop through all mutants, see if bug found at this length
  for outf in sorted(os.listdir(os.path.join(blt, 'stats/averages'))):
    if trace in outf:
        read_fd = open(os.path.join(blt, 'stats/averages', outf), 'r')
        lines = read_fd.readlines()
        if counter >= len(lines):
          continue
        line = lines[counter].split(',')
        if int(line[1]):
          if not caught[int(outf[12:-4])]:
            caught[int(outf[12:-4])] = 1
            # add the time it took to catch this bug
            time += float(line[2])
            # add the number of paths explored to catch this bug
            paths += int(line[3])

  num_caught = get_mutants_caught()
  if num_caught:
    write_fd.write(str(counter) + ','
        + str(num_caught) + ','
        + str(time/num_caught) + ','
        + str(paths/num_caught) + '\n')
  counter += 1

