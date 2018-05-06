package br.ufc.smd;

public class Consumer extends Thread {
	
	private Deposit dep;
	private long sleep, wait;
	private int total;

	public Consumer(Deposit d, long t) {
		dep = d;
		sleep = t;
		wait = 200;
		total = 20;
	}
	
	@Override
	public void run() {
		try {
			for(int i = 0; i < total; i++) {
				if(dep.getNumItems() > 0) {
					dep.output();
					sleep(sleep);
				}
				else {
					sleep(wait);
				}
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
