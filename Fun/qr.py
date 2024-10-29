import qrcode

img = qrcode.make("https://sumangalamjewellers.com/")
img.save("qr.png", "PNG")
