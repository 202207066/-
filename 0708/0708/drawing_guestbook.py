import tkinter as tk
from tkinter import colorchooser, simpledialog

class DrawingGuestbook:
    def __init__(self, root):
        self.root = root
        self.root.title("그림방명록 with 펜")
        self.pen_color = "black"
        self.pen_width = 3
        self.drawing_data = []  # (color, width, [(x0, y0), (x1, y1), ...])
        self.current_line = None

        # 펜 옵션 바
        option_frame = tk.Frame(root)
        option_frame.pack()
        tk.Button(option_frame, text="색상변경", command=self.choose_color).pack(side="left", padx=3)
        tk.Button(option_frame, text="두께변경", command=self.choose_width).pack(side="left", padx=3)
        tk.Button(option_frame, text="리플레이", command=self.replay).pack(side="left", padx=3)
        tk.Button(option_frame, text="지우기", command=self.clear_canvas).pack(side="left", padx=3)
        
        # 그림판
        self.canvas = tk.Canvas(root, bg="white", width=500, height=250)
        self.canvas.pack(pady=5)
        self.canvas.bind("<ButtonPress-1>", self.start_draw)
        self.canvas.bind("<B1-Motion>", self.draw_motion)
        self.canvas.bind("<ButtonRelease-1>", self.end_draw)

    def choose_color(self):
        color = colorchooser.askcolor(title="펜 색상 고르기")
        if color[1]:
            self.pen_color = color[1]

    def choose_width(self):
        w = simpledialog.askinteger("펜 두께", "1~20 중 숫자로 입력", minvalue=1, maxvalue=20)
        if w:
            self.pen_width = w

    def start_draw(self, event):
        self.current_line = [(event.x, event.y)]

    def draw_motion(self, event):
        last = self.current_line[-1]
        self.canvas.create_line(last[0], last[1], event.x, event.y,
                                fill=self.pen_color, width=self.pen_width, capstyle='round')
        self.current_line.append((event.x, event.y))

    def end_draw(self, event):
        # 한 획(Stroke)을 데이터로 저장
        if self.current_line:
            self.drawing_data.append((self.pen_color, self.pen_width, list(self.current_line)))
        self.current_line = None

    def clear_canvas(self):
        self.canvas.delete("all")
        self.drawing_data.clear()

    def replay(self):
        self.canvas.delete("all")
        def draw_replay(idx=0, seg=0):
            if idx >= len(self.drawing_data):
                return
            color, width, line = self.drawing_data[idx]
            if seg < len(line)-1:
                x0, y0 = line[seg]
                x1, y1 = line[seg+1]
                self.canvas.create_line(x0, y0, x1, y1, fill=color, width=width, capstyle='round')
                self.root.after(15, draw_replay, idx, seg+1)
            else:
                self.root.after(20, draw_replay, idx+1, 0)
        draw_replay()

if __name__ == "__main__":
    root = tk.Tk()
    app = DrawingGuestbook(root)
    root.mainloop()
