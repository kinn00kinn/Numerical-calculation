 plot [1:9] [1:4] log(x+1) title "log(x+1)",
 x title "一次近似",
 x-x**2/2 title "二次近似",
 x-x**2/2+x**3/3 title "三次近似",
 x-x**2/2+x**3/3-x**4/4 title "四次近似",
 x-x**2/2+x**3/3-x**4/4+x**5/5 title "五次近似",
 x-x**2/2+x**3/3-x**4/4+x**5/5-x**6/6 title "六次近似"