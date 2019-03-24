import processing.serial.*;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.awt.event.InputEvent; 
 
 Serial in;               //class=serial,object=in     
 Robot r;

 int b=1,x,y,mx=0,my=0;
 int c1,c2,c3;
 int[][] xy=new int[5][2];
 int i=0, j=0;
 
 void setup () 
 { 
     size(400, 300);
 
     in = new Serial(this, "COM35", 1200);
     try{ 
         r=new Robot();
       }
     catch (Exception e){text("Error : "+e,10,50); }
     frameRate(60);
 }
 
 void draw()
 {
   if (in.available()>0) 
   {
        c1=in.read(); 
       if((int)(c1 & 7<<0)== 2)
        { 
          c2= in.read();
            c3= in.read();
           
            if(abs(c1-c2)==c3)
            {
            x=(int)(c1>>3 | (c2<<2 & 31<<5));
            b=(int)(c2 & 7<<0);
            xy[i][0]=x;
            i++;
            if(i>4)
            i=0;
            }
        }
        else if((int)(c1 & 7<<0)==3)
        {
            c2= in.read();
            c3= in.read();
            if(abs(c1-c2)==c3)
            {
            y=(int)(c1>>3 | (c2<<2 & 31<<5));
            b=(int)(c2 & 7<<0);
            xy[j][1]=y;
            j++;
            if(j>4)
            j=0;
            }
        }
                
        for(int k=0; k < xy.length; k++)          //sum
        {
           mx=mx+xy[k][0];
           my=my+xy[k][1];
        }
        
                background(0);
                mx=mx/(xy.length);            //average
                my=my/(xy.length);
                
                if(my<100)
                {
                      r.keyPress(KeyEvent.VK_SPACE);
                      delay(10);
                      r.keyRelease(KeyEvent.VK_SPACE);
                      if(mx<10)
                      {
                      r.keyPress(KeyEvent.VK_A);
                      delay(10);
                      r.keyRelease(KeyEvent.VK_A);
                      }
                      if(mx>150)
                      {
                      r.keyPress(KeyEvent.VK_D);
                      delay(10);
                      r.keyRelease(KeyEvent.VK_D);
                      }
                 }
                 else if(my>200)
                 {
                      r.keyPress(KeyEvent.VK_X);
                      delay(10);
                      r.keyRelease(KeyEvent.VK_X);
                 }                
                 
               
               text((int)(mx),100,100); 
                      
               text((int)(my),100,150);
          
               text(b,100,200); 
               mx=0;my=0;
   }
 } 