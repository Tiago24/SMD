class OBB extends Colisor {
	constructor(centro, dimensoes, angulo) {
		super(centro);
		this.dimensoes = {
			largura: dimensoes.largura,
			altura: dimensoes.altura,
			meiaLargura: dimensoes.largura/2.0,
			meiaAltura: dimensoes.altura/2.0
		};
		this.angulo = angulo;
		this.cor = 200;
	}
	
	get medidas() {
		return this.dimensoes;
	}
  
	get vertices() {
		const dimensoes = this.dimensoes;
		
		var aux = [
			{x: -dimensoes.meiaLargura, y: -dimensoes.meiaAltura},
			{x: dimensoes.meiaLargura, y: -dimensoes.meiaAltura},
			{x: dimensoes.meiaLargura, y: dimensoes.meiaAltura},
			{x: -dimensoes.meiaLargura, y: dimensoes.meiaAltura}
		];
		
		const cosseno = cos(this.angulo);
		const seno = sin(this.angulo);
		
		for(var i = 0; i < aux.length; i++) {
			const x = aux[i].x*cosseno + aux[i].y*seno;
			const y = aux[i].y*cosseno - aux[i].x*seno;
			aux[i] = {x: x, y: y};
		}
		
		return aux;
	}
	
	set medidas(dimensoes) {
		this.dimensoes = {
			largura: dimensoes.largura,
			altura: dimensoes.altura,
			meiaLargura: dimensoes.largura/2.0,
			meiaAltura: dimensoes.altura/2.0
		};
	}
	
	desenhar() {
		fill(this.cor);
		
		beginShape();
		for(var i = 0; i < this.vertices.length; i++)
			vertex(this.vertices[i].x + this.centro.x, this.vertices[i].y + this.centro.y);
		endShape();
	}
	
	colidir(colisor) {
		if(colisor instanceof AABB) return colisor.colidirOBB(this);
		else if(colisor instanceof OBB) return this.colidirOBB(colisor);
		else if(colisor instanceof Sphere) return this.colidirSphere(colisor);
	}

	colidirOBB(colisor) {
		var p1 = this.vertices;
		var p2 = colisor.vertices;
		
		for(var i = 0; i < 4; i++) {
			p1[i].x += this.centro.x;
			p1[i].y += this.centro.y;
			p2[i].x += colisor.centro.x;
			p2[i].y += colisor.centro.y;
		}
		
		var eixos = new Array();
		var c1 = SAT.eixo(p1);
		var c2 = SAT.eixo(p2);
		for(var i = 0; i < 4; i++)
			eixos.push(c1[i], c2[i]);
		
		for(var i = 0; i < eixos.length; i++) {
			var eixo = eixos[i];
			var e1 = SAT.projetar(p1, eixo);
			var e2 = SAT.projetar(p2, eixo);
			
			if(e1.esquerda > e2.direita || e1.direita < e2.esquerda) return false;
		}
		
		return true;
	}

	colidirSphere(colisor) {
		var delta = {
			x: this.centro.x - colisor.centro.x,
			y: this.centro.y - colisor.centro.y
		};
		
		const seno = sin(-this.angulo);
		const cosseno = cos(-this.angulo);
		const x = delta.x*cosseno + delta.y*seno;
		const y = delta.y*cosseno - delta.x*seno;
		delta = {x: x, y: y};
		
		const aabb = new AABB({x: 0.0, y: 0.0}, this.dimensoes);
		const circulo = new Sphere(delta, colisor.raio);
		
		return (aabb.colidirSphere(circulo));
	}
}