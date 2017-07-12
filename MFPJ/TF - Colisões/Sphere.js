class Sphere extends Colisor {
	constructor(centro, raio) {
		super(centro);
		this.raio = raio;
		this.cor = 200;
	}
	desenhar() {
		fill(this.cor);
		ellipse(this.centro.x, this.centro.y, this.raio * 2.0, this.raio * 2.0);
	}
	
	colidir(colisor) {
		if(colisor instanceof AABB || colisor instanceof OBB) return colisor.colidirSphere(this);
		else if(colisor instanceof Sphere) return this.colidirSphere(colisor);
	}

	colidirSphere(colisor) {
		var dx = this.centro.x - colisor.centro.x;
		var dy = this.centro.y - colisor.centro.y;
		var distancia2 = dx * dx + dy * dy;
		var somaRaios = this.raio + colisor.raio;
		var somaRaios2 = somaRaios * somaRaios;
		return (distancia2 < somaRaios2);
	}
}