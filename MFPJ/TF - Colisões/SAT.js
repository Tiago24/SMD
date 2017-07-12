class SAT {
	static eixo(listaPontos) {
		var aux = new Array();
		
		for(var i = 0; i < listaPontos.length; i++) {
			const p1 = listaPontos[i];
			const p2 = listaPontos[(i+1) % listaPontos.length];
			
			const p = {x: p1.x - p2.x, y: p1.y - p2.y};
			aux.push({x: p.y, y: -p.x});
		}
		
		return aux;
	}
	
	static projetar(listaPontos, eixo) {
		var minimo = listaPontos[0].x*eixo.x + listaPontos[0].y*eixo.y;
		var maximo = minimo;
		
		for(var i = 1; i < listaPontos.length; i++) {
			const atual = listaPontos[i];
			var aux = atual.x*eixo.x + atual.y*eixo.y;
			if(aux < minimo) minimo = aux;
			else if(aux > maximo) maximo = aux;
		}
		
		return {esquerda: minimo, direita: maximo};
	}
}