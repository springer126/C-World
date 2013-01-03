import java.io.*;
import java.net.*;
class UDPClient{
    public static void main(String[] args)throws IOException{
        DatagramSocket client = new DatagramSocket();
        
       	while(true)
	{
	        BufferedReader in = new BufferedReader(new InputStreamReader(System.in,"utf-8"));
		String sendStr = in.readLine();
		byte[] sendBuf;
		sendBuf = sendStr.getBytes();
		InetAddress addr = InetAddress.getByName("127.0.0.1");
		int port = 5050;
		DatagramPacket sendPacket 
		    = new DatagramPacket(sendBuf ,sendBuf.length , addr , port);
		client.send(sendPacket);
		byte[] recvBuf = new byte[100];
		DatagramPacket recvPacket
		    = new DatagramPacket(recvBuf , recvBuf.length);
		client.receive(recvPacket);
		String recvStr = new String(recvPacket.getData() , 0 ,recvPacket.getLength());
		if(recvStr.equals("end"))
		{
			System.out.println("结束通信");
			break;
		}
		System.out.println("收到:" + recvStr);
	}
	
        client.close();
    }
}
