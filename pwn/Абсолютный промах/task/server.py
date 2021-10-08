import sys
import math

try:
    flag = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    triangle_sides = [int(input(f"Enter side {i+1}: ")) for i in range(3)]
    sys.stdout.flush()
except:
    print("Something just went wrong :)")
    sys.stdout.flush()
    quit()

if min(triangle_sides) < 100 or max(triangle_sides) > 1000:
    sys.stdout.flush()
    print("Every side should be more than 100 and less than 1000!")
    quit()

if max(triangle_sides) > sum(triangle_sides)-max(triangle_sides):
    sys.stdout.flush()
    print("Broken sides of a triangle rule!")
    quit()

half_sum = sum(triangle_sides)/2
result = math.sqrt(half_sum*(half_sum-triangle_sides[0])*(half_sum-triangle_sides[1])*(half_sum-triangle_sides[2])) + ord(flag[int(half_sum) % len(flag)])

print(f"Area of your triangle is {result}")
sys.stdout.flush()