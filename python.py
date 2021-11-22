class Employee:
    raise_amount = 1.04
    no_of_emps = 0
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.email = first + '.' +last + '@iit.com'
        self.pay = pay
        Employee.no_of_emps +=1 #we can use instance increment but why would we do that 
    def getname(self):
        return '{} {}' .format(self.first, self.last)
    
    def apply_raise(self):
        self.pay = int(self.pay * self(raise_amount)) ## also we can use Employee(raise_amout)
    
    @classmethod
    def set_raise_amt(cls, amount):
        cls. raise_amout = amount
        
emp_1 = Employee('Corey','schafer', 300)
emp_2 = Employee('sdf','sdf',333)
print(emp_1.email)
print(emp_1.getname()) #there is always self argument whenever instance is called
print(Employee.getname(emp_1))
emp_1.apply_raise()
print(emp_1.pay)
print(emp_1.__dict__) #namespace return all the values in the object

# Regular methods directly takes the instance as the argument for class method we just add a decorator
