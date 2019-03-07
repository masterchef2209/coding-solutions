with open('filename') as f:
    for line in f:
        do_something(line)

def do_something(line):
	line=line.rstrip()
	n=int(line)
	print(2*n-2)