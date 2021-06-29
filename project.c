#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <gtk/gtk.h>

char name[20];
char arr[20];
char com[20];
int id,no;

int main(int argc, char *argv[])
{
    
    GtkBuilder      *builder; 
    GtkWidget       *window;


    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "project.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
   
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

//list all the processes in the system
void on_button1_clicked()
{
    system("ps -A");
}

//list all the processes grouped by user
void on_button2_clicked()
{
    system("ps -u");
}

//list process ID of all the processes in the system
void on_button3_clicked()
{
    system("ps -eo pid ");   
}


void on_btn_run_clicked()
{
    printf("Enter Name of process to Run: ");
    scanf("%s",&name); 
    system(name);
}

void on_btn_stop_clicked()
{
    strcpy(com,"killall ");
		printf("Enter Name of process to be terminated: ");
		scanf("%s",&name); 
		strcat(com,name);
		system(com);
		getchar();
}

void on_btn_send_clicked()
{
    printf("Enter signal number: ");
    scanf("%d",&no);
    printf("Enter id of process: ");
    scanf("%d",&id); 
    snprintf(arr,20,"kill -%d %d",no,id);
    system(arr);
}

//display manual of the project
void on_btn_manual_clicked()
{
    system("man project");
}


// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
