import random
import numpy as np
import math
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from tkinter import filedialog
from tkinter import *

window = Tk()
window.title("문제 생성기")
window.geometry("360x600")

values = ["집합 문제", "두 점 문제", "세 점 문제", "네 점 문제"]
combobox = None
result_label = None
answer_label = None
current_sets = {"U": [], "A": [], "B": [], "C": [], "D": []}

def show_combobox():
    global combobox
    if combobox is None:
        combobox = ttk.Combobox(window, height=4, values=values)
        combobox.place(x=10, y=50, width=150)

def show_problem(event=None):
    global result_label, current_sets, answer_label
    if result_label:
        result_label.destroy()
    if answer_label:
        answer_label.destroy()
    
    selected = combobox.get()
    if selected == "집합 문제":
        c = Set()
        U, A, B = c.dataset(10, 5, 5)
        current_sets["U"] = U
        current_sets["A"] = A
        current_sets["B"] = B
        problem = f"전체 집합 U={U}이고, A={A}, B={B}일 때, 아래 집합을 구하여라.\n1) A U B\n2) A ∩ B\n3) A여집합\n4) B여집합\n5) A - B\n6) B - A"
    elif selected == "두 점 문제":
        c = Diagram2()
        A, B = c.dataset()
        current_sets["A"] = A
        current_sets["B"] = B
        problem = f"두 점 A={A}, B={B}과의 거리를 구하여라.\n1) 맨하탄 거리\n2) 유클리드 거리"
    elif selected == "세 점 문제":
        c = Diagram3()
        A, B, C = c.dataset()
        current_sets["A"] = A
        current_sets["B"] = B
        current_sets["C"] = C
        problem = f"세 점 A={A}, B={B}, C={C}이 있을 때,\n1) 삼각형의 변의 길이\n2) 삼각형의 넓이\n3) 2차 방정식의 계수"
    elif selected == "네 점 문제":
        c = Diagram4()
        A, B, C, D = c.dataset()
        current_sets["A"] = A
        current_sets["B"] = B
        current_sets["C"] = C
        current_sets["D"] = D
        problem = f"네 점 A={A}, B={B}, C={C}, D={D}이 있을 때,\n1) 사각형의 변의 길이\n2) 사각형의 넓이\n3) 3차 방정식의 계수"
    
    result_label = Label(window, text=problem, wraplength=340)
    result_label.place(x=10, y=100)

def show_answer():
    global answer_label
    if result_label:
        if answer_label:
            answer_label.destroy()
        
        selected = combobox.get()
        if selected == "집합 문제":
            c = Set()
            U = current_sets["U"]
            A = current_sets["A"]
            B = current_sets["B"]
            answer = f"1) {c.union(A, B)}\n2) {c.intersection(A, B)}\n3) {c.complement1(U, A)}\n4) {c.complement2(U, B)}\n5) {c.difference1(A, B)}\n6) {c.difference2(B, A)}"
        elif selected == "두 점 문제":
            c = Diagram2()
            A = current_sets["A"]
            B = current_sets["B"]
            answer = f"1) {c.m_dist(A, B)}\n2) {c.u_dist(A, B)}"
        elif selected == "세 점 문제":
            c = Diagram3()
            A = current_sets["A"]
            B = current_sets["B"]
            C = current_sets["C"]
            answer = f"1) {c.Linear(A, B, C)}\n2) {c.TriArea(A, B, C)}\n3) {c.SecondEq(A, B, C)}"
        elif selected == "네 점 문제":
            c = Diagram4()
            A = current_sets["A"]
            B = current_sets["B"]
            C = current_sets["C"]
            D = current_sets["D"]
            answer = f"1) {c.Linear(A, B, C, D)}\n2) {c.RecArea(A, B, C, D)}\n3) {c.ThirdEq(A, B, C, D)}"
            
        answer_label = Label(window, text=answer, wraplength=340)
        answer_label.place(x=10, y=250)

def show_solution():
    global answer_label
    if result_label:
        if answer_label:
            answer_label.destroy()
            
        selected = combobox.get()
        if selected == "집합 문제":
            solution = """집합 문제 풀이 방법:
1) A U B (합집합): A와 B의 모든 원소를 중복 없이 포함
2) A ∩ B (교집합): A와 B에 공통으로 있는 원소만 포함
3) A의 여집합: 전체집합 U에서 A의 원소를 제외한 나머지
4) B의 여집합: 전체집합 U에서 B의 원소를 제외한 나머지
5) A - B (차집합): A에서 B의 원소를 제외한 나머지
6) B - A (차집합): B에서 A의 원소를 제외한 나머지"""
        elif selected == "두 점 문제":
            solution = """두 점 사이의 거리 구하는 방법:
1) 맨하탄 거리: |x₁-x₂| + |y₁-y₂|
2) 유클리드 거리: √[(x₁-x₂)² + (y₁-y₂)²]"""
        elif selected == "세 점 문제":
            solution = """세 점으로 이루어진 도형 계산:
1) 삼각형 변의 길이: 두 점 사이의 유클리드 거리 계산
2) 삼각형 넓이: |x₁y₂ + x₂y₃ + x₃y₁ - y₁x₂ - y₂x₃ - y₃x₁| / 2
3) 2차 방정식: 세 점을 지나는 2차 함수 y = ax² + bx + c 구하기"""
        elif selected == "네 점 문제":
            solution = """네 점으로 이루어진 도형 계산:
1) 사각형 변의 길이: 연속된 두 점 사이의 유클리드 거리
2) 사각형 넓이: |x₁y₂ + x₂y₃ + x₃y₄ + x₄y₁ - y₁x₂ - y₂x₃ - y₃x₄ - y₄x₁| / 2
3) 3차 방정식: 네 점을 지나는 3차 함수 y = ax³ + bx² + cx + d 구하기"""
            
        answer_label = Label(window, text=solution, wraplength=340)
        answer_label.place(x=10, y=250)

class Set:
    def dataset(self, n, a, b):
        U = [i for i in range(1, n+1)]
        A = random.sample(U, a)
        B = random.sample(U, b)
        return U, A, B

    def union(self, A, B):
        union = sorted(list(set(A + B)))
        return f"A U B = {union}"

    def intersection(self, A, B):
        inter = sorted([i for i in A if i in B])
        return f"A ∩ B = {inter}"

    def complement1(self, U, A):
        comp = sorted([i for i in U if i not in A])
        return f"A의 여집합 = {comp}"

    def complement2(self, U, B):
        comp = sorted([i for i in U if i not in B])
        return f"B의 여집합 = {comp}"

    def difference1(self, A, B):
        difference = sorted([i for i in A if i not in B])
        return f"A - B = {difference}"

    def difference2(self, B, A):
        difference = sorted([i for i in B if i not in A])
        return f"B - A = {difference}"

class Diagram2:
    def dataset(self):
        A = [random.randint(1, 10), random.randint(1, 10)]
        B = [random.randint(1, 10), random.randint(1, 10)]
        return A, B

    def m_dist(self, A, B):
        return f"맨하탄 거리: {abs(A[0] - B[0]) + abs(A[1] - B[1])}"

    def u_dist(self, A, B):
        return f"유클리드 거리: {math.sqrt((A[0] - B[0])**2 + (A[1] - B[1])**2):.2f}"

class Diagram3:
    def dataset(self):
        A = [random.randint(1, 10), random.randint(1, 10)]
        B = [random.randint(1, 10), random.randint(1, 10)]
        C = [random.randint(1, 10), random.randint(1, 10)]
        return A, B, C

    def Linear(self, A, B, C):
        ab = math.sqrt((A[0] - B[0])**2 + (A[1] - B[1])**2)
        bc = math.sqrt((B[0] - C[0])**2 + (B[1] - C[1])**2)
        ca = math.sqrt((C[0] - A[0])**2 + (C[1] - A[1])**2)
        return f"AB={ab:.2f}, BC={bc:.2f}, CA={ca:.2f}"

    def TriArea(self, A, B, C):
        area = abs((A[0]*B[1] + B[0]*C[1] + C[0]*A[1]) - (A[1]*B[0] + B[1]*C[0] + C[1]*A[0])) / 2
        return f"삼각형의 넓이: {area:.2f}"

    def SecondEq(self, A, B, C):
        H = np.array([[A[0]**2, A[0], 1],
                    [B[0]**2, B[0], 1],
                    [C[0]**2, C[0], 1]])
        G = np.array([A[1], B[1], C[1]])
        solution = np.linalg.solve(H, G)
        return f"y = {solution[0]:.2f}x² + {solution[1]:.2f}x + {solution[2]:.2f}"

class Diagram4:
    def dataset(self):
        A = [random.randint(1, 10), random.randint(1, 10)]
        B = [random.randint(1, 10), random.randint(1, 10)]
        C = [random.randint(1, 10), random.randint(1, 10)]
        D = [random.randint(1, 10), random.randint(1, 10)]
        return A, B, C, D

    def Linear(self, A, B, C, D):
        ab = math.sqrt((A[0] - B[0])**2 + (A[1] - B[1])**2)
        bc = math.sqrt((B[0] - C[0])**2 + (B[1] - C[1])**2)
        cd = math.sqrt((C[0] - D[0])**2 + (C[1] - D[1])**2)
        da = math.sqrt((D[0] - A[0])**2 + (D[1] - A[1])**2)
        return f"AB={ab:.2f}, BC={bc:.2f}, CD={cd:.2f}, DA={da:.2f}"

    def RecArea(self, A, B, C, D):
        area = abs((A[0]*B[1] + B[0]*C[1] + C[0]*D[1] + D[0]*A[1]) -
                  (A[1]*B[0] + B[1]*C[0] + C[1]*D[0] + D[1]*A[0])) / 2
        return f"사각형의 넓이: {area:.2f}"

    def ThirdEq(self, A, B, C, D):
        H = np.array([[A[0]**3, A[0]**2, A[0], 1],
                    [B[0]**3, B[0]**2, B[0], 1],
                    [C[0]**3, C[0]**2, C[0], 1],
                    [D[0]**3, D[0]**2, D[0], 1]])
        G = np.array([A[1], B[1], C[1], D[1]])
        solution = np.linalg.solve(H, G)
        return f"y = {solution[0]:.2f}x³ + {solution[1]:.2f}x² + {solution[2]:.2f}x + {solution[3]:.2f}"

bt1 = Button(window, text="문제", command=show_combobox)
bt2 = Button(window, text="정답", command=show_answer)
bt3 = Button(window, text="문제풀이", command=show_solution)

bt1.place(x=10, y=20, width=80, height=20)
bt2.place(x=100, y=20, width=80, height=20)
bt3.place(x=190, y=20, width=80, height=20)

btn = Button(window, text="문제 생성", command=show_problem)
btn.place(x=170, y=50, width=60, height=20)

window.mainloop()