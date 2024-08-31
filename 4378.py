fromtext = "1234567890-=wertyuiop[sdfghjkl;'xcvbnm,./]\\"
totext   = "`1234567890-qwertyuiopasdfghjkl;zxcvbnm,.[]"

fromtext = fromtext.upper()

while True:
    try:
        s = input()
        i = 0  
        while(i < len(s)):
            if(s[i] in {'Q', 'A', 'Z'}):
                s = s[0:i] + s[i+1:]
            i+=1


        for i in range(len(fromtext)):
            s = s.replace(fromtext[i], totext[i])
        
        s = s.upper()
        print(s)
    except Exception as e:
        print(e)
        break;