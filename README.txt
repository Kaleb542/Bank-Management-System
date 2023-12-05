Comp Sci 371: Advanced Object-oriented Design
Group Project
Full Mark: 100
Report Submission Deadline: 12/15/2023
Advanced Bank Management System

Objective: To develop a C++ object-oriented program to implement a bank management system.

Project Overview: Your task is to develop a Bank Management System in C++ that encompasses user accounts, manager accounts, transactions, and a login system. The system involves three main classes: User, Transaction, and BankAccount. Additionally, there is a special class for bank managers. The following are the main requirements of this project. You are allowed to implement as many classes as you want to fulfill the following requirements.

Requirements:
• Implement a class to manage user bank accounts, including methods to create and delete users, load user's information from a file, and handle user logins. A typical bank account should have attributes such as account number, account type, balance, and customer information.
• User login information and account information should be stored in the users.txt file.
• Create a class to manage banking accounts, allowing users to perform actions like withdrawal, deposit, and printing account summaries.
    o  The Withdraw function verifies the availability of funds and deducts a specified amount from the user's account. If there are insufficient funds,  the user is promptly notified with          an error message.
    o Deposit enables the user to inject a specified amount of money into their account.
    o PrintAccountSummary exhibits the user's comprehensive transaction history along with their present account balance.
• Develop a specialized class for bank managers, providing login functionality and access to all user data.
• The login data for managers is stored in managers.txt. No class will have the capability to create a manager account; instead, the manager's name and password must be manually inserted into the managers.txt file. Initially, the first names of you and your group members, along with their corresponding passwords, will be stored inside managers.txt.

Your program should start with the following options:
1. User Login
2. Create Account
3. Manager Login
4. Exit
For any further clarification, please contact your instructor.

Your project will be evaluated according to the following criteria
✓ Using pointers 5 marks
✓ Using classes, objects, constructors (default, parametric, copy) 10 marks
✓ Encapsulation, Polymorphism, Inheritance 10 marks (will receive a bonus of 5 marks)
✓ String 5 marks
✓ File, memory management list 5 marks
✓ Correctly working program 10 marks

Rubrics
Correct functionalities 45
Report 15
Presentation 30
Peer Review 10

Functionalities
You need to implement the topics, concepts, and syntax that we covered in class. Examples include pointers, class definitions, header files, encapsulation, polymorphism, inheritance, File I/O, and strings.

Report
Your report should work as documentation for your project. The report should include your detailed workflow, UML design, class design, attributes, and class behaviors

Presentation
On week 15 you will be presenting your project during the class hour. Every group will have around 10 minutes to present. 5 minutes will be allowed for the presentation and 5 minutes for question answering. During the presentation, you will also be asked for a code walk-through.

Peer review report
In the peer review report, you will be covering the challenges you faced to finish the project including the approaches you followed to address these challenges. This will also include your comments on group member’s participation and cooperation. Each student will evaluate their group members using the criteria below:
    • On a scale of 1 to 4, rate your teammate on the effort she/he put into researching and developing the project.
        1. Student did not collect any information that relates to the research topic following the rubrics presented earlier.
        2. Student collected very little information relating to the research topic following the rubrics presented earlier.
        3. Student collected a reasonable amount of information and most of it is related to the research topic following the rubrics presented earlier.
        4. Student collected a great deal of information and all of it is related to the research topic following the rubrics presented earlier.
    • On a scale of 1 to 4, rate your teammate on how well he/she shares information and code with the group.
        1. Student did not relay any information to other teammates.
        2. Student relayed very little information that related to the research topic to other teammates.
        3. Student relayed some information and most of it was related to the research topic.
        4. Student relayed a great deal of information and all of it related to the research topic.
    • On a scale of 1 to 4, rate your teammate on well he/she perform their duties relating to the project.
        1. Did not perform any duties of the assigned team role.
        2. Performed very few duties.
        3. Perform nearly all duties.
        4. Performed all the duties assigned.
    • On a scale of 1 to 4, rate your teammate on how well he/she shared the workload.
        1. Always relied on others to do the work.
        2. Rarely did the assigned work – often needed reminding.
        3. Usually did the assigned work – rarely needed reminding.
        4. Always did the assigned work without having to be reminded.
    • On a scale of 1 to 4, rate your teammate on how well he/she attended meetings or communicated with group members.
        1. Missed most group meetings. Did not respond to any communications.
        2. Frequently missed group meetings and frequently responded to team members.
        3. Attended most of the meetings. Responded in a couple of days to any communication.
        4. Attended all group meetings. Responded to emails in a reasonable time.

Besides these grading, please include any comments and reviews you may have on group work and group members.
