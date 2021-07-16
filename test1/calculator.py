from playsound import playsound
while(1):
    print("When you poop, do you?")
    print("A. Pull \nB. Push")

    var1 = input()
    var1 = var1.upper()
    if var1 == "A" :
        print("ssshhhllllluuuurrrpppp")
        playsound('S.mp3')

    if var1 == "B" :
        print("bbbllluuurrrpppp")
        playsound('B.mp3')
