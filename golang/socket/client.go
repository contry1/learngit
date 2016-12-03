package main
import(
"fmt"
"net"
"bufio"
)



func main(){
	conn,err := net.Dial("tcp",":5010")
	if err!=nil{
		fmt.Printf("get client2 err:",err);
	}
	
fmt.Fprintf(conn,"hello!\n");
   data,err :=bufio.NewReader(conn).ReadString('\n')
   if err!=nil{
   	fmt.Printf("get client err:",err);
   }
   fmt.Printf("%#v\n",data);
	

}
