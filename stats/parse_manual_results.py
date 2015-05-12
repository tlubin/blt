with open('manual_results.txt', 'r') as fd:
    lines = fd.readlines()

totalfound = 0
for i in range(10):
    found = 0
    for j in range(i*100, (i+1)*100):
        if 'found' in lines[j]:
            found += 1
    totalfound += found
    print "{0} - {1} found {2}".format(i*100, (i+1)*100-1, found)
print "TOTAL: {0} of {1} found".format(totalfound, 1000)
