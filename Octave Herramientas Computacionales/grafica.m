x=linspace(0,6*pi,200);
y1=sin(x).*exp(-0.2*x);
y2=cos(x).*exp(-0.1*x);
plot(x,y1,'k-','linewidth',1.5);
hold on
plot(x,y2,'r-','linewidth',1.5);
hold off
set(gca,'Fontsize',25,'Fontweight','bold')
xlabel('Delta ','Fontsize',20,'Fontweight','bold')
legend('uno','dos')
grid on
text(pi,0.6,'texto','FontSize',20,'color','r')
