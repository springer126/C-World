import java.io.*;
import java.net.*;
class UDPServer{
    public static void main(String[] args)throws IOException{
        DatagramSocket  server = new DatagramSocket(5050);
        byte[] recvBuf = new byte[100];
        DatagramPacket recvPacket 
            = new DatagramPacket(recvBuf , recvBuf.length);
	while(true)
	{
		server.receive(recvPacket);
		String recvStr = new String(recvPacket.getData() , 0 , recvPacket.getLength());
		if(recvStr.equals("end"))
			break;

		int port = recvPacket.getPort();
		InetAddress addr = recvPacket.getAddress();
		System.out.println("From: "+addr.getHostAddress()+" : " + recvStr);
		
		String sendStr = "Hello ! I'm Server";
		byte[] sendBuf;
		sendBuf = sendStr.getBytes();
		DatagramPacket sendPacket 
		    = new DatagramPacket(sendBuf , sendBuf.length , addr , port );
		server.send(sendPacket);
	}
       
        server.close();
    }
}
