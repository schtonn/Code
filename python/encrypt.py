from PIL import Image
import math

def encode(txt):
    n=len(txt)
    w=math.ceil(n**0.5)
    img=Image.new("RGB",(w,w),0x0)
    x,y=0,0
    for i in txt:
        index=ord(i)
        col=((index&0xff00)>>8,index&0xFF,127)
        img.putpixel((x,y),col)
        if x==w-1:
            x=0
            y+=1
        else:x+=1
    return img

def decode(img):
    w,h=img.size
    txt=[]
    for y in range(h):
        for x in range(w):
            r,g,b=img.getpixel((x,y))
            if(r|g|b==0):continue
            index=(r<<8)+g
            txt.append(chr(index))
    return ''.join(txt)

def en():
    with open("plain.txt",encoding="utf-8") as f:
        txt=f.read()
    img=encode(txt)
    img.save("out.bmp")
def de():
    txt=decode(Image.open("out.bmp","r"))
    with open("decode.txt","w",encoding="utf-8") as f:
        f.write(txt)

en()