arr=['L','L','L','X','R','R','R']
final=[]
final.append(' '.join(arr))
rev=list(reversed(arr))
size=len(arr)
empty=3
def frogjump(l,empty):
      if l==rev:
            return True
      if empty+1<size and l[empty+1]=='R':
            l[empty],l[empty+1]=l[empty+1],l[empty]
            empty+=1
            final.append(' '.join(l))
            if frogjump(l,empty):
                  return True
            final.pop()
            empty-=1
            l[empty],l[empty+1]=l[empty+1],l[empty]
      if empty+2<size and l[empty+2]=='R':
            l[empty],l[empty+2]=l[empty+2],l[empty]
            empty+=2
            final.append(' '.join(l))
            if frogjump(l,empty):
                  return True
            final.pop()
            empty-=2
            l[empty],l[empty+2]=l[empty+2],l[empty]
      if empty-1>-1 and l[empty-1]=='L':
            l[empty],l[empty-1]=l[empty-1],l[empty]
            empty-=1
            final.append(' '.join(l))
            if frogjump(l,empty):
                  return True
            final.pop()
            empty+=1
            l[empty],l[empty-1]=l[empty-1],l[empty]
      if empty-2>-1 and l[empty-2]=='L':
            l[empty],l[empty-2]=l[empty-2],l[empty]
            empty-=2
            final.append(' '.join(l))
            if frogjump(l,empty):
                  return True
            final.pop()
            empty+=2
            l[empty],l[empty-2]=l[empty-2],l[empty]

      return False
print(frogjump(arr,3))
for u in final:
      print(u)