dict = {}

for i in range(1, 11):
    dict[i] = i**2

print(dict) # {1: 1, 2: 4, 3: 9, 4: 16, 5: 25, 6: 36, 7: 49, 8: 64, 9: 81, 10: 100}


for key in dict:
  if key % 2 == 0:
    del dict[key]

print(dict) # {1: 1, 3: 9, 5: 25, 7: 49, 9: 81}
