var colisorMovel, colisorFixo;
var flag = true;

function keyPressed(event) {
	if(flag) {
		flag = false;

		switch(key) {
			case 'a':
			case 'A':
				colisorMovel = new AABB({x: mouseX, y: mouseY}, {largura: 50.0, altura: 75.0});
				break;
			case 'o':
			case 'O':
				colisorMovel = new OBB({x: mouseX, y: mouseY}, {largura: 50.0, altura: 75.0}, Math.random() * TWO_PI);
				break;
			case 's':
			case 'S':
				colisorMovel = new Sphere({x: mouseX, y: mouseY}, 32.5);
				break;
			case '1':
				colisorFixo = new AABB({x: width / 2.0, y: height / 2.0}, {largura: 50.0, altura: 75.0});
				break;
			case '2':
				colisorFixo = new OBB({x: width / 2.0, y: height / 2.0}, {largura: 50.0, altura: 75.0}, Math.random() * TWO_PI);
				break;
			case '3':
				colisorFixo = new Sphere({x: width / 2.0, y: height / 2.0}, 32.5);
				break;
			}
	}
}

function keyReleased(event) {
	flag = true;
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	
	colisorMovel = new AABB({x: width / 2.0, y: height / 2.0}, {largura: 50.0, altura: 75.0});
	colisorFixo = new AABB({x: width / 2.0, y: height / 2.0}, {largura: 50.0, altura: 75.0});
  
  println("Após clicar com o mouse na tela, pressione as seguintes teclas para mudar os objetos.");
  println("1: Objeto Fixo para AABB");
  println("2: Objeto Fixo para OBB");
  println("3: Objeto Fixo para Círculo");
  println("A: Objeto Móvel para AABB");
  println("O: Objeto Móvel para OBB");
  println("S: Objeto Móvel para Círculo");
}

function draw() {
	background(100);

	colisorMovel.centro = {x: mouseX, y: mouseY};
	
	colisorFixo.desenhar();
	colisorMovel.desenhar();
	
	if(colisorMovel.colidir(colisorFixo)) colisorMovel.cor = "red";
	else colisorMovel.cor = "blue";
}

function intervalo(valor, minimo, maximo) {
  return max(minimo, min(maximo, valor));
}