const fila = [1, 2, 3, 4, 5, 6, 7, 8, 9];
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
console.log("Opção 1: ver fila.");
console.log("Opção 2: adicionar ao final da fila.");
console.log("Opção 3: remover primeiro da fila.");
function mostrarFila() {
    console.log(fila);
}
function adicionarFila() {
    rl.question("Digite o numero a ser adidionado \n", (response) =>{
        fila.push(parseInt(response));
        console.log(fila);
        rl.close()
    }
)}
function removerFila() {
    fila.shift();
    console.log(fila);
    rl.close();
}
function perguntarOpcao() {
    rl.question("Digite a opção (1, 2 ou 3): ", (response) => {
        const opcao = parseInt(response);
        switch (opcao) {
            case 1:
                mostrarFila();
                break;
            case 2:
                adicionarFila();
                break;
            case 3:
                removerFila();
                break;
            default:
                console.log("Opção inválida. Por favor, escolha 1, 2 ou 3.");
        }

        perguntarOpcao();
    });
}
perguntarOpcao(); 
