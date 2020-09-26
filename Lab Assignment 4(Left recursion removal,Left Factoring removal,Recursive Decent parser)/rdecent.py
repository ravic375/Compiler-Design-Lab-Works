from collections import defaultdict

found = False

sequence = []

prod = defaultdict(list)

def recurse(r,prod,string,seq):
	global found
	global sequence
	#print(seq)
	if found:
		return
	if r==string:
		found = True
		sequence = seq
		#print(sequence)
		return
	counter = 0
	for i in range(len(r)):
		if r[i]>='a' and r[i]<='z':
			counter = counter +1
	if counter > len(string):
		return 
	for i in range(len(r)):
		if r[i]>='A' and r[i]<='Z':
			#print(r[i])
			for j in prod[r[i]]:
				p = ''
				if not j=='$':
					p = j
				temp = ''
				if not i==len(r)-1:
					temp = r[:i] + p + r[i+1:]
				else:
					temp = r[:i] + p
				ts = seq.copy()
				ts.append(temp)
				recurse(temp,prod,string,ts)
			break



while True:
	l=input()
	if l=='END':
		break
	l = l.split('->')
	#print(l[1].split('|'))
	prod[l[0]]=(l[1].split('|'))

string = input('Enter the string: ')

recurse('S',prod,string,['S'])

print(sequence)
