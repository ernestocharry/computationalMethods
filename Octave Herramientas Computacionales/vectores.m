a=[1 2 0]
b=[2 3 0]
dot(a,b)
norm(a)
a'
cross(a,b)
%quiver(1,2)
%quiver3(1, 2,3)
x=[1;2;3]
y=[4;5;6]
x*y'
x'*y
x.*y

f='1/(1+x^2)'
lims=[-5,5]
fplot(f,lims)

x=linspace(-2,3,100);
y=exp(x).*(sin(x).^2)
plot(x,y,'c','Linewidth',2);grid on

f=@(x)[x^2-1+exp(x)]
fplot (@sin, [-10, 10], 201);
fplot("x^2-1+exp(x)",[-2 2])
fzero(f,-1)
