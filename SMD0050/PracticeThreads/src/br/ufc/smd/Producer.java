package br.ufc.smd;

public class Producer extends Thread {
	
	private Deposit dep;
	private long sleep;
	private int total;

	public Producer(Deposit d, long t) {
		dep = d;
		sleep = t;
		total = 100;
	}

	@Override
	public void run() {
		try {
			for(int i = 0; i < total; i++) {
				dep.input();
				sleep(sleep);
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
