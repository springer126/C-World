import java.io.*;
import java.net.*;

class SendThread extends Thread
{
	private DatagramSocket sock;
	private BufferedReader reader;
	private InetAddress addr;
	private int port = 5050;
	private DatagramPacket sendPacket;
	
	SendThread(DatagramSocket sock)
	{
		this.sock = sock;
		
	}
	
	public void run() throws Exception
	{
			
				addr = InetAddress.getByName("192.168.1.105");
				reader = new BufferedReader(new InputStreamReader(System.in,"utf-8"));
			
			

	   	   while(true)
	   	   {
							System.out.print("% ");
							String sendStr = reader.readLine();
							byte[] sendBuf;
							sendBuf = sendStr.getBytes();
							sendPacket = new DatagramPacket(sendBuf ,sendBuf.length , addr , port);
							sock.send(sendPacket);
	   	   }       
   	 
  }

}
	
class RecvThread extends Thread
{
	private DatagramSocket sock;
	private DatagramPacket recvPacket;
	
	RecvThread(DatagramSocket sock)
	{
		this.sock = sock;
	}
	
	public void run()  throws Exception
	{
   	   while(true)
   	   {
						byte[] recvBuf = new byte[100];
		        recvPacket = new DatagramPacket(recvBuf , recvBuf.length);
						sock.receive(recvPacket);
						String recvStr = new String(recvPacket.getData() , 0 ,recvPacket.getLength());
						if(recvStr.equals("end"))
						{
							System.out.println("结束通信");
							break;
						}
						
						int port = recvPacket.getPort();
						InetAddress addr = recvPacket.getAddress();
						System.out.println("From: "+addr.getHostAddress()+" : " + recvStr);
   	   	}       
  }

}


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
