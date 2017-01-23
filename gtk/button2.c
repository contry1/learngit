    #include <gtk/gtk.h>  
      
    void close_app(GtkWidget *window,gpointer data)  
    {  
        gtk_main_quit();  
    }  
      
    int main(int argc,char *argv[])  
    {  
        GtkWidget *window;  
        GtkWidget *button1;  
        GtkWidget *button2;  
        GtkWidget *button3;  
        GtkWidget *Hbox;  
        GtkWidget *Vbox;  
      
        gtk_init(&argc,&argv);  
      
        //new window  
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
        gtk_window_set_title(GTK_WINDOW(window),"Layout demo");  
        gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);  
        gtk_window_set_default_size(GTK_WINDOW(window),200,200);  
        g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(close_app),NULL);   
          
        //新建了3个按钮和两个组装盒  
        button1 = gtk_button_new_with_label("登陆");  
        button2 = gtk_button_new_with_label("下线");  
        button3 = gtk_button_new_with_label("发送");  
      
        Hbox = gtk_hbox_new(TRUE,0);  
        Vbox = gtk_vbox_new(TRUE,0);  
          
        //将button1和button2放在Hbox上  
        gtk_box_pack_start(GTK_BOX(Hbox),button1,FALSE,FALSE,0);  
        gtk_box_pack_start(GTK_BOX(Hbox),button2,FALSE,FALSE,0);  
      
        //将button3和Hbox放在Vbox上  
        gtk_box_pack_start(GTK_BOX(Vbox),GTK_WIDGET(Hbox),FALSE,FALSE,0);  
        gtk_box_pack_start(GTK_BOX(Vbox),button3,FALSE,FALSE,0);  
          
        //将Vbox添加到window容器上  
        gtk_container_add(GTK_CONTAINER(window),Vbox);  
        gtk_widget_show_all(window);  
        gtk_main();  
      
        return 0;  
    }  