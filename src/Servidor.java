import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.ArrayList;

public class Servidor extends Thread {
	
	
	InetAddress mip;
	private DatagramSocket ds;
	int contador = 0;
	String Mensaje;
	ArrayList<String> mensajes = new ArrayList<>() ;
	public Servidor() {
		
	}
	
	@Override
	public void run() {
		
		try {
			
			ds = new DatagramSocket(5000);
		
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		while(true) {
			
			recibir();
			
		 if (contador == 2) {
			 contador = 0;
				if(mensajes.get(0).toString() == mensajes.get(1).toString()) {
					System.out.println("empate");
					
					mensajes.remove(0);
					mensajes.remove(1);
					
					
				}
				
				
				
				
			}
			
		}
	}
	
	
	
	public void enviar(String PPT) {
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				
				
				DatagramPacket p = new DatagramPacket(PPT.getBytes(), PPT.getBytes().length,mip,5000);
				try {
					ds.send(p);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
		}).start();
		
	}
	
	public void recibir() {
		byte[] buf = new byte[64]; // 47k
	
		DatagramPacket p = new DatagramPacket(buf, buf.length);
		try {
		
			ds.receive(p);
			contador ++;
			Mensaje = new String(p.getData());
			System.out.println(Mensaje);
			mensajes.add(Mensaje);
			System.out.println(contador);
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
