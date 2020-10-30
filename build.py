import os
cfiles=os.listdir('src')
for i in range(0,len(cfiles)):
    cfiles[i]="src/"+cfiles[i]
test=os.listdir('test')
for i in test:
    cfiles.append('test/'+i)
command='gcc '
for i in cfiles:
    command+=i+' '
command+='-o out/cxml'
os.system(command)
