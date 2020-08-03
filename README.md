# Computer-room-reservation-system
In order to prevent the use of the machine room disorderly, I design this system

## 1.we have three identities available to use the system
+ student: StudnetId | Name | Password
+ teacher: TeacherId | Name | Password
+ administrator: Name | Password
----------------------------------------
## 2.Introduction of computer room 
 ### we have 3 rooms in total
 + Room 1 ---contains 20 students
 + Room 2 ---contains 50 students
 + Room 3 ---contains 100 students
----------------------------------------
## 3.Application introduction
+ The requested order is cleared by the administrator.
+ The student can apply for the use on the day from Mon to Fri of the coming next week, and can choose Morning or Afternoon.
+ The teacher is responsible for reviewing the request and the appointment according to the actual situation (Pass Or Not Pass).
----------------------------------------
## 4.System specific requirements
### [First, everyone need to select an identity to log in the system]
- Student
- Teacher
- Administrator
- Exit

### [After the validation, enter the sub menu]
+ student: StudnetId | Name | Password
+ teacher: TeacherId | Name | Password
+ administrator: Name | Password

### [Function of Student Account]
+ Apply the application
+ Check account application
+ View all the application's information
+ Cancel the application
+ Log out

### [Function of Teacher Account]
+ View all the application's information
+ Audit the application from students
+ Log out

### [Function of Admin Account]
+ Add the account
+ View all account's information
+ View all the room's information
+ Clear the application
+ Log out
