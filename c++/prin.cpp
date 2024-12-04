#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear la ventana
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Mi primera interfaz gráfica");

    // Cargar las fuentes
    sf::Font fuenteImpact;
    if (!fuenteImpact.loadFromFile("impact.ttf")) { // Asegúrate de tener el archivo "impact.ttf" en tu directorio de trabajo
        std::cerr << "Error al cargar la fuente Impact" << std::endl;
        return 1;
    }

    sf::Font fuenteArial;
    if (!fuenteArial.loadFromFile("arial.ttf")) { // Asegúrate de tener el archivo "arial.ttf" en tu directorio de trabajo
        std::cerr << "Error al cargar la fuente Arial" << std::endl;
        return 1;
    }

    // Crear un texto para "Mi primera página"
    sf::Text textoPrimeraPagina("Mi primera pagina", fuenteImpact, 36);
    textoPrimeraPagina.setPosition(250, 200);
    textoPrimeraPagina.setStyle(sf::Text::Bold);

    // Crear un texto para "Brandon Suárez"
    sf::Text textoNombre("Brandon Suárez", fuenteArial, 14);
    textoNombre.setPosition(330, 250);

    // Bucle principal
    while (ventana.isOpen()) {
        // Manejar eventos
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                ventana.close();
        }

        // Limpiar la ventana (pintar de negro)
        ventana.clear(sf::Color::Black);

        // Dibujar los textos en la ventana
        ventana.draw(textoPrimeraPagina);
        ventana.draw(textoNombre);

        // Mostrar la ventana
        ventana.display();
    }

    return 0;
}

