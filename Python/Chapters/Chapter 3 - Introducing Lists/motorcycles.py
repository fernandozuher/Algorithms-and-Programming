motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles[0] = 'ducati'
print(motorcycles)

motorcycles[0] = 'honda'
motorcycles.append('ducati')
print(motorcycles)

motorcycles.insert(0, 'sony')
print(motorcycles)

del motorcycles[0]
print(motorcycles)

last = motorcycles.pop()
print(motorcycles)
print(f"Last popped element: {last}.")

last2 = motorcycles.pop(0)
print(motorcycles)

motorcycles.append('ducati')
print(motorcycles)

motorcycles.remove('suzuki')
print(motorcycles)