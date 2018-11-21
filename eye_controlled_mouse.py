from tkinter import *
import easygui
from pymouse import PyMouse
import cv2
import picamera
from numpy import *
import numpy as np
from pylab import *
from timeit import timeit
import math

global screen_center_x
global screen_center_y
global screen_top_x
global screen_top_y
global screen_bottom_x
global screen_bottom_y
global k_system
global time_end
global ex
global ey
global flag


m = PyMouse()
x_dim, y_dim = m.screen_size()

'''
    face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
    eye_cascade = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')
    face_cascade.load('/Library/OpenCV/opencv/data/haarcascades/haarcascade_frontalface_default.xml')
    eye_cascade.load('/Library/OpenCV/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml')
'''

def run ():
    cap = cv2.VideoCapture(0)
    time_end = 0
    flag = 0

    while(True):
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
        '''
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
            
        for (x,y,w,h) in faces:
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        eyes = eye_cascade.detectMultiScale(roi_gray)
        for (ex,ey,ew,eh) in eyes:
        #cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
        ret,th1 = cv2.threshold(roi_gray,20,255,cv2.THRESH_BINARY)
        
        #cv2.imshow('img',th1)
        #if cv2.waitKey(30) & 0xFF == ord('q'):
        #break
        '''
    
        roi_eye = gray
        ret,th1 = cv2.threshold(roi_eye,30,255,cv2.THRESH_BINARY)
        rows = gray.shape[0]
        circles = cv2.HoughCircles(th1, cv2.HOUGH_GRADIENT, 1.7, rows / 1,param1=100, param2=20,minRadius=0, maxRadius=0)
    
        if circles is not None:
            circles = np.uint16(np.around(circles))
            for i in circles[0, :]:
                center = (i[0], i[1])                                       #圆心坐标
                cv2.circle(th1, center, 1, (0, 100, 100), 3)
                radius = i[2]
                cv2.circle(th1, center, radius, (255, 0, 255), 3)
                #print (center)
                #print (i[2])
            
                if radius >= 5:         #注意：5要修改
                    
                    ex = i[0]
                    ey = i[1]
                    
                    '''
                    m.move(x,y)
                    '''
                    if flag == 1:       #眨眼；睁眼，停止计时
                        time_end = time.time()
                        flag = 0

        '''
        while circle is None        #运算时间作计时器
            x = 0
            x = x + 1
            if x > 1
            
                break
        '''
        
        if circles is None and flag != 1:   #时间差作计时器
            time_start = time.time()        #眨眼；闭眼，计时开始
            flag = 1
        time_length = time_end - time_start     #眨眼；时间差
        if time_length >= 0:
        print (time_length)
    
        '''
        cv2.imshow('img',th1)
        cv2.imshow('img2',roi_eye)
        if cv2.waitKey(30) & 0xFF == ord('q'):
            break
        '''

    cap.release()
    out.release()
    cv2.destroyAllWindows()

def collect ():
    cap = cv2.VideoCapture(0)
    time_end = 0
    flag = 0
    
    while(True):
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
        '''
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
            
        for (x,y,w,h) in faces:
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        eyes = eye_cascade.detectMultiScale(roi_gray)
        for (ex,ey,ew,eh) in eyes:
        #cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
        ret,th1 = cv2.threshold(roi_gray,20,255,cv2.THRESH_BINARY)
            
        #cv2.imshow('img',th1)
        #if cv2.waitKey(30) & 0xFF == ord('q'):
        #break
        '''
        
        roi_eye = gray
        ret,th1 = cv2.threshold(roi_eye,30,255,cv2.THRESH_BINARY)
        rows = gray.shape[0]
        circles = cv2.HoughCircles(th1, cv2.HOUGH_GRADIENT, 1.7, rows / 1,param1=100, param2=20,minRadius=0, maxRadius=0)
        
        if circles is not None:
            circles = np.uint16(np.around(circles))
            for i in circles[0, :]:
                center = (i[0], i[1])                                       #圆心坐标
                cv2.circle(th1, center, 1, (0, 100, 100), 3)
                radius = i[2]
                cv2.circle(th1, center, radius, (255, 0, 255), 3)
                #print (center)
                #print (i[2])
                
                if radius >= 5:         #注意：5要修改
                    '''
                        ex = i[0]
                        ey = i[1]
                        m.move(x,y)
                        '''
                    if flag == 1:       #眨眼；睁眼，停止计时
                        time_end = time.time()
                        flag = 0
    
    '''
        while circle is None        #运算时间作计时器
        x = 0
        x = x + 1
        if x >
        break
        '''
            
            if circles is None and flag != 1:   #时间差作计时器
            time_start = time.time()        #眨眼；闭眼，计时开始
            flag = 1
                time_length = time_end - time_start     #眨眼；时间差
                    if time_length >= 0:
                        print (time_length)
                        
                        '''
                            cv2.imshow('img',th1)
                            cv2.imshow('img2',roi_eye)
                            if cv2.waitKey(30) & 0xFF == ord('q'):
                            break
                            '''

cap.release()
out.release()
cv2.destroyAllWindows()


root = Tk()
root.title('眼控鼠标')
v = IntVar()
group=LabelFrame(root,text='采集点')
group.pack(padx=50)

v.set(1)
Language = [('上顶点',1),
            ('中点', 2),
            ('下顶点',3 ),
        ]
for lang,num in Language:
    b = Radiobutton(group,text=lang,variable=v,value=num,indicatoron=False,padx=30,pady=3)
    l = Label(group,textvariable=v) 
    l.pack()
    b.pack(anchor=W,fill=X) 
    
theButton1=Button(root,text='采集'',command=collect')
theButton1.pack(pady=20)
theButton2=Button(root,text='开始'',command=run')
theButton2.pack(pady=20)
mainloop()


k_system = (screen_top_y - screen_bottom_y)/(screen_top_x - screen_bottom_x)
angle_eye_system = math.atan(k_system)
angle_trans = pi/2 - angle_eye_system
matrix_point = mat([(ey - screen_center_y),(ex - screen_center_x)])
matrix_trans = mat([mat.cos(angle_trans),mat.sin(angle_trans)],[-mat.sin(angle_trans),mat.cos(angle_trans)])
matrix_screen = matrix_point * matrix_trans
mouse_x = matrix_screen[0,0]
mouse_y = matrix_screen[0,1]
