player = "X"
list1 = [ [0,1,2], 
            [3,4,5],
            [6,7,8]]

while(1):


    print(list1[0])
    print(list1[1])
    print(list1[2])


    mainInput =  int(input("Type in a number 1- 9 "))
    if mainInput == 0 or mainInput == 1 or mainInput == 2:
        row = 0
        mainInput -2
    if mainInput == 3 or mainInput == 4 or mainInput == 5:
        row = 1
        mainInput -= 3
    if mainInput == 6 or mainInput == 7 or mainInput == 8:
        row = 2      
        mainInput -= 6
    list1[row][mainInput] = player
    
    if list1[0][0] == list1[0][1] and list1[0][1] == list1[0][2]:
        print(list1[0][0] ,"Wins!!")
    if list1[1][0] == list1[1][1] and list1[1][1] == list1[1][2]:
        print(list1[1][0] ,"Wins!!")
    if list1[2][0] == list1[2][1] and list1[2][1] == list1[2][2]:
        print(list1[2][0] ,"Wins!!")

    if list1[0][0] == list1[1][0] and list1[1][0] == list1[2][0]:
        print(list1[0][0] ,"Wins!!")
    if list1[0][1] == list1[1][1] and list1[1][1] == list1[2][1]:
        print(list1[0][1] ,"Wins!!")
    if list1[0][2] == list1[1][2] and list1[1][2] == list1[2][2]:
        print(list1[0][2] ,"Wins!!")

    if list1[0][0] == list1[1][1] and list1[1][1] == list1[2][2]:
        print(list1[0][0] ,"Wins!!")
    if list1[0][2] == list1[2][2] and list1[2][2] == list1[2][0]:
        print(list1[0][2] ,"Wins!!")


    if player == "X":
        player = "O"
    elif player == "O":
        player = "X"
    
