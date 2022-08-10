# coding:utf-8

import tkinter as tk

from functools import partial
from random import randint

from numpy.random import choice



"""

round start:
    - choose next attack-team.

round boss:
Boss of Voice

round assistant:
    - assistant skills

round attacker:
    - normal attack
    - special skills

round attacker:
    - normal attack
    - special skills

round end:


"""

students = ['林禹',
            # '李子优',
            
            # '刘嘉琦',
            '蔡子渊',
            '刘晨奕',
        '朱奕璇',
        # '朱瀚阳',
        '樊庆',
        # '颜硕a',
        '曾奕嘉',
        '温梓豪',
        '黄炯天',
        '葛寄楮',
        '许康麟',
        "户梓璇",
        '潘泊']
lens = len(students)


gui = tk.Tk()
gui.attributes('-topmost',1)
gui.geometry('200x490')
# gui.config(bg='black')
gui.title('Voice King')


class Boss:
    def __init__(self, name, health,armor,attack):
        self.name = name
        self.health = health
        self.armor = armor
        self.attack = attack
        self.stat_change = [0,0,0]
        self.special_choose = 0
        self.special = [('声之形','波动攻击'),
                        ('声之形','波动攻击'),
                        ('声之形','波动攻击')]
    
    def stat(self):
        return '生命:\t%d%+d\n护甲:\t%d%+d\n攻击力:\t%d%+d'%\
                    (self.health,self.stat_change[0],
                     self.armor,self.stat_change[1],
                     self.attack,self.stat_change[2],)
    
    def special_text(self):
        return '技能：%s\n%s'%self.special[self.special_choose]
        
    def normal_attack(self):
        pass
    
    def special_attack(self):
        pass
    
    def special1(self,pool):
        pass
    
    def special2(self,pool):
        pass
    
    def special3(self,pool):
        pass


class Student:
    def __init__(self,name):
        self.name = name
        self.health = 50 + randint(1,20)
        self.armor = 1 + randint(1,5)
        self.attack = 2 + randint(1,4)
        self.change = [0,0,0]

    def special(self):
        k = randint(1,3)
        if k == 1:
            self.change[0] += 10
        if k == 2:
            self.change[1] += 2
        if k == 3:
            self.change[2] += 2

    def endround(self):
        self.health += self.change[0]
        self.armor += self.change[1]
        self.attack += self.change[2]
        self.change = [0,0,0]

def next():
    global in_pool,out_pool,st,boss,true_answer
    
    out_pool = in_pool
    for i in in_pool:
        st[i].change = [0,0,0]
        
    A = 0
    for j in range(3):
        i = in_pool[j]
        if st[i].health >= 0:
            st[i].change[0] = st[i].armor - boss.attack
            st[i].change[0] += st[i].change[0]
            if true_answer[j] == 0:
                st[i].change[0] -= boss.attack
        
            A += st[i].attack
            
        if st[i].health < 0 :
            st[i].change[0] += 15
            if true_answer[j] == 1:
                st[i].change[0] += 15
                
        if true_answer[j] == 1:
            st[i].special()
    boss.stat_change[0] = boss.armor - A
    
    
    in_pool = choice(len(students),3,replace=False)
    
    for i in in_pool:
        st[i].endround()
    refresh_now()
    
    refresh_last()
    
    global boss_stat
    boss_stat.config(text=boss.stat())
    
    boss.health += boss.stat_change[0]

        
        
boss = Boss('Voice King', 340, 10, 10)
st = []
for i in range(len(students)):
    st.append(Student(students[i]))

tk.Label(gui,text=boss.name).grid(row=0,column=0,columnspan=2, sticky="w")

tk.Button(gui,text='Next',command=next,).grid(row=0,column=2, sticky="w")

boss_stat = tk.Label(gui,text=boss.stat(),justify='left')
boss_stat.grid(row=1,column=0,rowspan=2,columnspan=2)

tk.Label(gui,text=boss.special_text(),justify='left').grid(row=1,column=2,rowspan=2, columnspan=2 ,sticky="w")

def refresh_now():
    global in_pool,now_labels
    for i in range(3):
        now_labels[i].config(text=st[in_pool[i]].name)
        now_labels[i+3].config(text=st[in_pool[i]].health)
        now_labels[i+6].config(text=st[in_pool[i]].armor)
        now_labels[i+9].config(text=st[in_pool[i]].attack)

def refresh_last():
    global out_pool,last_labels
    for i in range(3):
        last_labels[i].config(text=st[out_pool[i]].name)
        last_labels[i+3].config(text='%d'%(st[out_pool[i]].health)+'%+d'%(st[out_pool[i]].change[0]))
        last_labels[i+6].config(text='%d'%st[out_pool[i]].armor+'%+d'%st[out_pool[i]].change[1])
        last_labels[i+9].config(text='%d'%st[out_pool[i]].attack+'%+d'%st[out_pool[i]].change[2])

true_answer = [0,0,0]
def change_answer(j):
    global now_labels,true_answer
    
    true_answer[j] = 0 if true_answer[j] else 1
    print(true_answer)
    for i in range(3):
        if true_answer[i]==0:
            now_labels[i].config(bg='gray')
        elif true_answer[i]==1:
            now_labels[i].config(bg='red')
    
#  main start

tk.Label(gui,text='本次').grid(row=3,column=0, sticky="w")
tk.Label(gui,text='血').grid(row=4,column=0, sticky="w")
tk.Label(gui,text='甲').grid(row=5,column=0, sticky="w")
tk.Label(gui,text='攻').grid(row=6,column=0, sticky="w")

in_pool = choice(len(students),3,replace=False)
now_labels = []
for i in range(3):
    now_labels.append(tk.Button(gui,text=st[in_pool[i]].name,command=partial(change_answer,i)))
    now_labels[-1].grid(row=3,column=i+1, sticky="w")
for i in range(3):
    now_labels.append(tk.Label(gui,text=st[in_pool[i]].health))
    now_labels[-1].grid(row=4,column=i+1, sticky="w")
for i in range(3):
    now_labels.append(tk.Label(gui,text=st[in_pool[i]].armor))
    now_labels[-1].grid(row=5,column=i+1, sticky="w")
for i in range(3):
    now_labels.append(tk.Label(gui,text=st[in_pool[i]].attack))
    now_labels[-1].grid(row=6,column=i+1, sticky="w")

out_pool = [0,1,2]
last_labels = []
tk.Label(gui,text='上轮').grid(row=7,column=0, sticky="w")
tk.Label(gui,text='血').grid(row=8,column=0, sticky="w")
tk.Label(gui,text='甲').grid(row=9,column=0, sticky="w")
tk.Label(gui,text='攻').grid(row=10,column=0, sticky="w")
for i in range(3):
    last_labels.append(tk.Label(gui,text=st[in_pool[i]].name))
    last_labels[-1].grid(row=7,column=i+1, sticky="w")
for i in range(3):
    last_labels.append(tk.Label(gui,text='%d'%(st[in_pool[i]].health)+'%+d'%(st[in_pool[i]].change[0])))
    last_labels[-1].grid(row=8,column=i+1, sticky="w")
for i in range(3):
    last_labels.append(tk.Label(gui,text='%d'%st[in_pool[i]].armor+'%+d'%st[in_pool[i]].change[1]))
    last_labels[-1].grid(row=9,column=i+1, sticky="w")
for i in range(3):
    last_labels.append(tk.Label(gui,text='%d'%st[in_pool[i]].attack+'%+d'%st[in_pool[i]].change[2]))
    last_labels[-1].grid(row=10,column=i+1, sticky="w")


gui.mainloop()
