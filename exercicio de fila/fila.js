const readline = require('readline');

class Queue {
    constructor() {
        this.items = [];
    }

    enqueue(item) {
        this.items.push(item);
    }

    dequeue() {
        if (this.isEmpty()) {
            return "A fila está vazia.";
        }
        return this.items.shift();
    }

    isEmpty() {
        return this.items.length === 0;
    }

    viewQueue() {
        return "Fila atual: " + this.items.join(", ");
    }
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const queue = new Queue();

const menu = () => {
    console.log("\n=== Menu da Fila ===");
    console.log("1. Visualizar fila");
    console.log("2. Adicionar item à fila");
    console.log("3. Remover item da fila");
    console.log("4. Sair");
    rl.question("Escolha uma opção: ", (option) => {
        switch(option) {
            case '1':
                console.log(queue.viewQueue());
                menu();
                break;
            case '2':
                rl.question("Digite o item para adicionar: ", (item) => {
                    queue.enqueue(item);
                    console.log(`'${item}' adicionado à fila.`);
                    menu();
                });
                break;
            case '3':
                console.log(queue.dequeue());
                menu();
                break;
            case '4':
                rl.close();
                break;
            default:
                console.log("Opção inválida.");
                menu();
        }
    });
};

menu();
