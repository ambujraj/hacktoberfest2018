import turtle
from playsound import playsound
window=turtle.Screen()
window.title("Py-Pong by Kuru")
window.bgcolor('pink')
window.bgpic("Py-Pong wallpaper.gif")
window.setup(height=700,width=800)
window.tracer(0)
score_a=0
score_b=0
#Pad 1
pad1=turtle.Turtle()
pad1.speed(0)
pad1.shape('square')
pad1.shapesize(6.5,1.5)
pad1.color("#c493ff")
pad1.penup() 
pad1.goto(x=-350,y=0)
#Pad 2
pad2=turtle.Turtle()
pad2.speed(0)
pad2.shape('square')
pad2.shapesize(6.5,1.5)
pad2.color("#c493ff")
pad2.penup() 
pad2.goto(x=350,y=0)

#Ball
ball=turtle.Turtle()
ball.speed(0)
ball.shape('circle')
ball.shapesize(1.5,1.5)
ball.color("#e50b5a")
ball.penup() 
ball.goto(x=0,y=0)
ball.dx=0.9          #Adjust the speed of the ball here
ball.dy=0.8

#Scoreboard

board=turtle.Turtle()
board.speed(0)
board.color("white")
board.penup()
board.goto(0,305)
board.write("Player A : {}  Player B : {} ".format(score_a,score_b), align="center", font=("Courrier",25,"bold") )

#Paddle speeds can be adujusted here

def pad1up():
        y=pad1.ycor()
        y+=20
        pad1.sety(y)

def pad1down():
        y=pad1.ycor()
        y-=20
        pad1.sety(y)

def pad2up():
        y=pad2.ycor()
        y+=20
        pad2.sety(y)

def pad2down():
        y=pad2.ycor()
        y-=20
        pad2.sety(y)

#Window Binding
window.listen() 
window.onkeypress(pad1up,'w')
window.onkeypress(pad1down,'s')
window.onkeypress(pad2up,'Up')
window.onkeypress(pad2down,'Down')
playsound("Py-Pong_music.mp3",0)
while True:
        window.update()
        ball.setx(ball.xcor()+ball.dx)
        ball.sety(ball.ycor()+ball.dy)
        if ball.ycor()>320:
                ball.sety(320)
                ball.dy*=-1
        if ball.ycor()<-320:
                ball.sety(-320)
                ball.dy*=-1
        if ball.xcor()>390:
                ball.goto(0,0)
                ball.dx*=-1
                score_a+=1
                board.clear()
                board.write("Player A : {}  Player B : {} ".format(score_a,score_b), align="center", font=("Courrier",25,"bold") )

        if ball.xcor()<-390:
                ball.goto(0,0)
                score_b+=1
                ball.dx*=-1
                board.clear()
                board.write("Player A : {}  Player B : {} ".format(score_a,score_b), align="center", font=("Courrier",25,"bold") )

        if ball.xcor()>340 and (ball.xcor()<350) and (ball.ycor()<pad2.ycor()+65) and (ball.ycor()>pad2.ycor()-65):
                ball.setx(340)
                ball.dx*=-1
        if ball.xcor()<-340 and ball.xcor()>-350 and (ball.ycor()<pad1.ycor()+65) and (ball.ycor()>pad1.ycor()-65):
                ball.setx(-340)
                ball.dx*=-1


