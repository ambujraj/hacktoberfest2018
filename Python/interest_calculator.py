#Interest calculator

print('Interest Calculator')
amount = float(input('Principal Amount ?'))
roi = float(input('Rate of Interest ?'))
years = int(input('Duration (years)'))
total = (amount * amount)
interest = total - amount
print('\nInterest = %0.2f' %interest)
