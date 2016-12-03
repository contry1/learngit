package main
import(
"fmt"
"log"
"net"
"bufio"
)
func handlecon(conn net.Conn){
   data,err :=bufio.NewReader(conn).ReadString('\n')
   if err!=nil{
   	log.Fatal("get client err:",err);
   }
   fmt.Printf("%#v\n",data);
   fmt.Fprintf(conn,"hello!\n");
   conn.Close();
   
}

func main(){
	ln,err := net.Listen("tcp",":5010")
	if err!=nil{
		log.Fatal("get client2 err:",err);
	}
	for {
		conn,err := ln.Accept()
		if err!=nil{
			log.Fatal("get client3 err:",err);
		}
		go handlecon(conn)
	}

}
