# 7,2,5,10,8
# 32 // 2 = 16
# smallest = 10 = max(newspapers_read_times)
# largest = 32 = sum(newspapers_read_times)

# 2 3 5 7
# 17 // 3 = 5
# smallest = 7 = max(newspapers_read_times)
# largest = 17 = sum(newspapers_read_times)

from typing import List

def check(newspapers_read_times: List[int], num_coworkers: int, time: int) -> bool:
    # Initialize the sum of reading times for the current worker
    timeSum = 0
    # Iterate over each newspaper's read time
    for read_time in newspapers_read_times:
        # If adding the current newspaper's read time doesn't exceed the limit, add it to the current worker's time sum
        if timeSum + read_time <= time:
            timeSum += read_time
        else:
            # If it does exceed, switch to the next coworker
            num_coworkers -= 1
            # If there are no coworkers left, it's not possible to read all newspapers within the time limit
            if num_coworkers == 0:
                return False
            # Start summing reading times for the next worker
            timeSum = read_time
    # If you went through all newspapers without running out of coworkers, it's possible
    return True

def newspapers_split(newspapers_read_times: List[int], num_coworkers: int) -> int:
    l = max(newspapers_read_times)
    r = sum(newspapers_read_times)
    minTime = -1
    while l <= r:
        m = l + (r-l)//2
        if check(newspapers_read_times, num_coworkers, m):
            minTime = m
            r = m - 1
        else:
            l = m + 1
    
    return minTime

if __name__ == "__main__":
    newspapers_read_times = [int(x) for x in input().split()]
    num_coworkers = int(input())
    res = newspapers_split(newspapers_read_times, num_coworkers)
    print(res)
