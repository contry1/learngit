#include <stdio.h>  
#include <gtk/gtk.h>  
#include <stdlib.h>  
  
/*开关按钮： 
 *  由一般按钮派生而来，只是开关按钮只有两个状态，通过点击 
 *  可以切换。 
 *  开关按钮是复选按钮和单选按钮的基础，所以单选按钮和复选按钮继承了 
 *  许多开关按钮的函数调用 
 */  
  
    GtkWidget *button1;  
    GtkWidget *button2;  

void callback(GtkWidget *widget, gpointer data)  
{  
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button1))){  
        g_print("发送消息\n");  
    }else{  
        g_print("nothing\n");  
    }  
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button2))){  
        g_print(" 客户端断开\n");  
    }else{  
        g_print("nothing\n");  
    }  
}  
  
/*退出回调函数*/  
gint delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)  
{  
    gtk_main_quit();  
    return FALSE;  
}  
  
  
int main(int argc,char *argv[])  
{  
    GtkWidget *window;  
    GtkWidget *button;  
    GtkWidget *box;  
  
    /*初始化*/  
    gtk_init(&argc,&argv);  
  
    /*创建窗口*/  
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  
    /*这个一般必要有delete_event信号到主窗口*/  
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(delete_event),NULL);  
      
    /*设置窗口宽度*/  
    // gtk_container_set_border_width(GTK_CONTAINER(window),200); 
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),200,200); 
    /*设置窗口标题*/  
    gtk_window_set_title(GTK_WINDOW(window),"客户端");  
      
    /*创建一个组装盒子*/  
    box = gtk_hbox_new((gboolean)FALSE,0);  
  
    /*设置一个开关按钮*/  
    button1 = gtk_toggle_button_new_with_label("连接");
    gtk_box_pack_start(GTK_BOX(box),button1,FALSE,FALSE,0);  
  
    
  
    button2 = gtk_button_new_with_label("发送");
    gtk_box_pack_start(GTK_BOX(box),button2,FALSE,FALSE,0);  
    g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(callback),NULL);  
  
    gtk_container_add(GTK_CONTAINER(window),box);  
  
    gtk_widget_show(window);  
    gtk_widget_show(box);  
    // gtk_widget_show(button1);  
    // gtk_widget_show(button2); */ 
      
  
    gtk_main();  
    return 0;  
}  