class AABB extends Colisor {
	constructor(centro, dimensoes) {
		super(centro);
		this.dimensoes = {
			largura: dimensoes.largura,
			altura: dimensoes.altura,
			meiaLargura: dimensoes.largura / 2.0,
			meiaAltura: dimensoes.altura / 2.0
		};
		this.cor = 200;
	}
	
  	get arestas() {
		return {
			esquerda: this.centro.x - this.dimensoes.meiaLargura,
			direita: this.centro.x + this.dimensoes.meiaLargura,
			topo: this.centro.y - this.dimensoes.meiaAltura,
			piso: this.centro.y + this.dimensoes.meiaAltura
		};
    }
  
    get vertices() {
		return [
			{x: -this.dimensoes.meiaLargura, y: -this.dimensoes.meiaAltura},
			{x: -this.dimensoes.meiaLargura, y: this.dimensoes.meiaAltura},
			{x: this.dimensoes.meiaLargura, y: this.dimensoes.meiaAltura},
			{x: this.dimensoes.meiaLargura, y: -this.dimensoes.meiaAltura}
		];
    }
  
	desenhar() {
		fill(this.cor);
		rect(this.centro.x - this.dimensoes.meiaLargura,
			 this.centro.y - this.dimensoes.meiaAltura,
			 this.dimensoes.largura, this.dimensoes.altura);
	}
	
	colidir(colisor) {
		if(colisor instanceof AABB) return this.colidirAABB(colisor);
		else if(colisor instanceof OBB) return this.colidirOBB(colisor);
		else if(colisor instanceof Sphere) return this.colidirSphere(colisor);
	}
	
	colidirAABB(colisor) {
		var xMin1 = this.arestas.esquerda;
		var xMax1 = this.arestas.direita;
		var xMin2 = colisor.arestas.esquerda;
		var xMax2 = colisor.arestas.direita;
		var yMin1 = this.arestas.topo;
		var yMax1 = this.arestas.piso;
		var yMin2 = colisor.arestas.topo;
		var yMax2 = colisor.arestas.piso;

		return (xMin1 < xMax2 && xMax1 > xMin2 && yMin1 < yMax2 && yMax1 > yMin2);
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
		var d = {
			x: colisor.centro.x - this.centro.x,
			y: colisor.centro.y - this.centro.y
		};
		
		const faixaValores = {
			x: intervalo(d.x, -this.dimensoes.meiaLargura, this.dimensoes.meiaLargura),
			y: intervalo(d.y, -this.dimensoes.meiaAltura, this.dimensoes.meiaAltura)
		};
		
		const pontoProximo = {
			x: this.centro.x + faixaValores.x,
			y: this.centro.y + faixaValores.y
		};
		
		d = {
			x: pontoProximo.x - colisor.centro.x,
			y: pontoProximo.y - colisor.centro.y
		};
		
		const delta = d.x*d.x + d.y*d.y;
		const raio2 = colisor.raio*colisor.raio;
		
		return (delta < raio2);
	}
}