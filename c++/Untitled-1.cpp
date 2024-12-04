#include <SFML/Graphics.hpp>
#include <iostream>

sf::Sprite imgSprite;


void abrirVentanaNueva(sf::Texture& fondoTextura, const std::string& titulo, const std::string& contenido, const std::string& botonTexto, const std::string& archivoPDF = "") {
    sf::RenderWindow ventana(sf::VideoMode(1100, 600), titulo);
    ventana.setFramerateLimit(60);

    sf::Font fuenteArial;
    if (!fuenteArial.loadFromFile("Arial.ttf")) {
        std::cerr << "Error al cargar la fuente Arial" << std::endl;
        return;
    }

    sf::Font fuenteImpact;
    if (!fuenteImpact.loadFromFile("Impact.ttf")) {
        std::cerr << "Error al cargar la fuente Impact" << std::endl;
        return;
    }

    sf::Text textoContenido(contenido, fuenteArial, 20);
    textoContenido.setPosition(20, 100);
    textoContenido.setFillColor(sf::Color::White); // Cambia el color del texto a blanco
    textoContenido.setOutlineColor(sf::Color::Black); // Establece el color del borde
    textoContenido.setOutlineThickness(2); // Establece el grosor del borde

    sf::Sprite spriteFondo(fondoTextura);
    spriteFondo.setScale(
        static_cast<float>(ventana.getSize().x) / static_cast<float>(fondoTextura.getSize().x),
        static_cast<float>(ventana.getSize().y) / static_cast<float>(fondoTextura.getSize().y)
    );

    sf::RectangleShape botonDescarga(sf::Vector2f(250, 50));
    sf::Text textoBotonDescarga;

    if (!archivoPDF.empty()) {
        botonDescarga.setFillColor(sf::Color::White); // Color blanco
        botonDescarga.setPosition(ventana.getSize().x / 2 - 125, 500);

        textoBotonDescarga.setString(botonTexto);
        textoBotonDescarga.setFont(fuenteArial);
        textoBotonDescarga.setCharacterSize(16);
        textoBotonDescarga.setPosition(botonDescarga.getPosition().x + 20, botonDescarga.getPosition().y + 10);
        textoBotonDescarga.setFillColor(sf::Color::Black);
    }

    while (ventana.isOpen()) {
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                ventana.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!archivoPDF.empty()) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(ventana);
                        if (botonDescarga.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            std::cout << "Descargando archivo: " << archivoPDF << std::endl;
                            // Ejecutar el comando para abrir el PDF (sistema dependiente)
                            system(("start " + archivoPDF).c_str());
                        }
                    }
                }
            }
        }

        ventana.clear();
        ventana.draw(spriteFondo);
        ventana.draw(textoContenido);
        if (!archivoPDF.empty()) {
            ventana.draw(botonDescarga);
            ventana.draw(textoBotonDescarga);
        }
        ventana.display();
    }
}

int main() {
    sf::RenderWindow ventana(sf::VideoMode(1200, 800), "noticias en edomex mexico");

    sf::Texture imgTexture;
    if (!imgTexture.loadFromFile("ce.png")) {
        std::cerr << "Error al cargar la imagen cecy.png" << std::endl;
        return 1;
    }

    imgSprite.setTexture(imgTexture);
    imgSprite.setPosition(650, 250);
    imgSprite.setScale(0.4f, 0.4f);

    sf::Texture fondoTexturaPrincipal;
    sf::Texture fondoTexturaNuevaVentana;
    if (!fondoTexturaPrincipal.loadFromFile("a.jpg")) {
        std::cerr << "Error al cargar la textura de fondo para la pagina principal" << std::endl;
        return 1;
    }
    if (!fondoTexturaNuevaVentana.loadFromFile("a.jpg")) {
        std::cerr << "Error al cargar la textura de fondo para las nuevas ventanas" << std::endl;
        return 1;
    }

    sf::Font fuenteArial;
    if (!fuenteArial.loadFromFile("Arial.ttf")) {
        std::cerr << "Error al cargar la fuente Arial" << std::endl;
        return 1;
    }

    sf::Font fuenteImpact;
    if (!fuenteImpact.loadFromFile("Impact.ttf")) {
        std::cerr << "Error al cargar la fuente Impact" << std::endl;
        return 1;
    }

    sf::Text textoTitulo("Noticias en Edomex", fuenteImpact, 72);
    textoTitulo.setPosition(20, 20);
    textoTitulo.setStyle(sf::Text::Bold);
    textoTitulo.setFillColor(sf::Color(0, 100, 0)); // Color verde oscuro fuerte
    textoTitulo.setOutlineThickness(1);
    textoTitulo.setOutlineColor(sf::Color::Black);

    std::string parrafo = "Noticias al momento en todo edomex";
    sf::Text textoParrafo(parrafo, fuenteArial, 18);
    textoParrafo.setPosition(20, 120);
    textoParrafo.setFillColor(sf::Color::White);
    textoParrafo.setStyle(sf::Text::Regular);
    textoParrafo.setOutlineColor(sf::Color::Black);
    textoParrafo.setOutlineThickness(1);

    // Colocar el fondo para la ventana principal
    sf::Sprite spriteFondoPrincipal(fondoTexturaPrincipal);
    spriteFondoPrincipal.setScale(
        static_cast<float>(ventana.getSize().x) / static_cast<float>(fondoTexturaPrincipal.getSize().x),
        static_cast<float>(ventana.getSize().y) / static_cast<float>(fondoTexturaPrincipal.getSize().y)
    );

    // Botón 1: Detalles de Programas
    sf::RectangleShape botonProgramas(sf::Vector2f(250, 50));
    botonProgramas.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonProgramas.setPosition(20, 300);

    sf::Text textoBotonProgramas("noticias del mes ", fuenteImpact, 16);
    textoBotonProgramas.setPosition(botonProgramas.getPosition().x + 20, botonProgramas.getPosition().y + 10);
    textoBotonProgramas.setFillColor(sf::Color::White);

    // Botón 2: Proceso de Admisión
    sf::RectangleShape botonAdmision(sf::Vector2f(250, 50));
    botonAdmision.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonAdmision.setPosition(20, 400);

    sf::Text textoBotonAdmision("sucesos", fuenteImpact, 16);
    textoBotonAdmision.setPosition(botonAdmision.getPosition().x + 20, botonAdmision.getPosition().y + 10);
    textoBotonAdmision.setFillColor(sf::Color::White);

    // Botón 3: Vinculacion con la industria
    sf::RectangleShape botonVinculacion(sf::Vector2f(250, 50));
    botonVinculacion.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonVinculacion.setPosition(20, 500);

    sf::Text textoBotonVinculacion("eventos ", fuenteImpact, 16);
    textoBotonVinculacion.setPosition(botonVinculacion.getPosition().x + 20, botonVinculacion.getPosition().y + 10);
    textoBotonVinculacion.setFillColor(sf::Color::White);

    // Botón 4: Servicios Escolares
    sf::RectangleShape botonServicios(sf::Vector2f(250, 50));
    botonServicios.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonServicios.setPosition(300, 300);

    sf::Text textoBotonServicios("deportes", fuenteImpact, 16);
    textoBotonServicios.setPosition(botonServicios.getPosition().x + 20, botonServicios.getPosition().y + 10);
    textoBotonServicios.setFillColor(sf::Color::White);

    // Botón 5: Noticias y Eventos
    sf::RectangleShape botonNoti(sf::Vector2f(250, 50));
    botonNoti.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonNoti.setPosition(300, 400);

    sf::Text textoBotonNoti("tecnología", fuenteImpact, 16);
    textoBotonNoti.setPosition(botonNoti.getPosition().x + 20, botonNoti.getPosition().y + 10);
    textoBotonNoti.setFillColor(sf::Color::White);

    // Botón 6: Direccion
    sf::RectangleShape botonAddress(sf::Vector2f(250, 50));
    botonAddress.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonAddress.setPosition(300, 500);

    sf::Text textoBotonAdress("en vivo ", fuenteImpact, 16);
    textoBotonAdress.setPosition(botonAddress.getPosition().x + 20, botonAddress.getPosition().y + 10);
    textoBotonAdress.setFillColor(sf::Color::White);

    // Botón 6: ACERCA De
    sf::RectangleShape botonAbout(sf::Vector2f(250, 50));
    botonAbout.setFillColor(sf::Color(150, 150, 150)); // Color gris
    botonAbout.setPosition(200, 600);

    sf::Text textoBotonAbout("accidentes", fuenteImpact, 16);
    textoBotonAbout.setPosition(botonAbout.getPosition().x + 20, botonAbout.getPosition().y + 10);
    textoBotonAbout.setFillColor(sf::Color::White);



while (ventana.isOpen()) {
    sf::Event event;
    while (ventana.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            ventana.close();
        
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(ventana);
                
                // Botón 1: Detalles de Programas
                if (botonProgramas.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Noticias del Mes", 
                    "\nFecha: Diciembre 02, 2024\n\n"
                    "Trágico tiroteo masivo en un pueblo del centro de México\n, vinculado a la creciente violencia de los cárteles de la droga. "
                    "El ataque resultó en la muerte de ocho personas\n, con dos heridos graves. Las autoridades federales y locales están trabajando\n juntas para identificar a los responsables "
                    "y prevenir más incidentes en la región.\n\n"
                    "Este hecho es parte de un patrón más amplio de violencia en el centro-norte del país\n, en áreas fuertemente influenciadas por los cárteles del narcotráfico.\n\n", 
                    "Sucesos del Mes\n", 
                    "start https://www.gob.mx/siap/articulos/conmemorando-el-mes-de-noviembre-318561?idiom=es");
                }
                
                // Botón 2: Proceso de Admisión
                if (botonAdmision.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Sucesos Recientes", 
                    "\nAccidente fatal en la autopista México-Pachuca: Un motociclista pierde la vida tras ser impactado por un automovilista. "
                    "\nEl accidente ocurrió en un tramo de alto tráfico de la carretera\n, lo que provocó una interrupción significativa en la circulación durante varias horas\n. "
                    "Las autoridades locales están investigando\n la causa del accidente y los responsables\n están siendo identificados.\n\n"
                    "A su vez, se reportó la suspensión temporal de vuelos\n en el Aeropuerto Internacional Felipe Ángeles debido\na la presencia de un banco de niebla denso, "
                    "\nlo que afectó a varios vuelos nacionales\n e internacionales durante la madrugada\n del 2 de diciembre.\n\n", 
                    "Eventos Disponibles", 
                    "start https://www.gob.mx/siap/articulos/tema-suceso");
                }
                
                // Botón 3: Industria
                if (botonVinculacion.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Eventos Industriales", 
                    "\nEl sector industrial de Edomex está viendo un crecimiento significativo con múltiples\n eventos y conferencias que se llevarán a cabo en las próximas semanas. \n"
                    "\nDestacan en la agenda eventos como exposiciones de tecnología\n, seminarios de innovación empresarial y ferias de empleo,\n que brindarán oportunidades valiosas para profesionales y empresas del sector.\n\n"
                    "\nCon más de 500 empresas involucradas, estos eventos son fundamentales para fortalecer\n los lazos comerciales y mejorar el panorama industrial en la región.\n "
                    "Además, se están implementando tecnologías avanzadas en la gestión\n de residuos y energías renovables, en línea con los objetivos de sostenibilidad regional.\n", 
                    "\nEventos Relevantes\n", 
                    "Doc2.pdf");
                }
                
                // Botón 4: Servicios Escolares
                if (botonServicios.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Deportes", 
                    "Este mes, Tecámac se convierte en sede del Nacional de Flag Football\n, con la participación de más de 600 equipos provenientes de diversas regiones del país\n y cuatro países invitados. "
                    "\nEl evento se llevará a cabo en el parque estatal Sierra Hermosa\n y se espera una asistencia superior a las 75,000 personas durante los cinco días del evento.\n\n"
                    "\nEl campeonato contará con equipos de diferentes niveles y categorías\n, destacándose la presencia de selecciones nacionales y profesionales, que mostrarán\n un nivel competitivo de clase mundial.\n\n"
                    "\nEste evento es considerado uno de los más importantes en el calendario deportivo de México\n, promoviendo el fútbol americano y el desarrollo de jóvenes talentos en todo el país.\n", 
                    "\nPlanificación Académica y Estudiantil\n", 
                    "start https://www.fmfa.org");
                }
                
                // Botón 5: Noticias
                if (botonNoti.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Tecnología y Noticias", 
                    "\nApexCoder, la comunidad más grande de desarrollo y programación, te ofrece un espacio para mantenerte informado\n sobre la últimas noticias tecnológicas y reportes de incidencias en la industria.\n "
                    "Si eres programador o desarrollador de software, no dudes en unirte a nuestra página en Facebook \npara reportar incidentes, compartir experiencias y resolver problemas técnicos con otros profesionales.\n\n"
                    "\nAdemás, ApexCoder proporciona guías de programación, tutoriales y recursos sobre mejores práctica\n, ayudando a los desarrolladores a mejorar sus habilidades y mantenerse al día con las últimas\n tendencias tecnológicas.\n", 
                    "\nComunidad y Noticia\n", 
                    "start https://www.facebook.com/people/Apexcoder-Dmc/pfbid0CxxLRMHXKoJWecs3dpHF8kS95PCh4egHxEXrWaWS9xZupyzPAHMi5yiW7BtC1S7Vl/?rdid=vCnNXl6Tlnu0kYPj&share_url=https%3A%2F%2Fwww.facebook.com%2Fshare%2F15Sd3PKC7d%2F");
                }
                
                // Botón 6: Dirección
                if (botonAddress.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // Abrir la página web en el navegador predeterminado
                    system("start https://www.nmas.com.mx/en-vivo/?canal=forotv");
                }
                
                // Botón 7: Acerca de
                if (botonAbout.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    abrirVentanaNueva(fondoTexturaNuevaVentana, "Accidentes Recientes", 
                    "\nRecientemente, se ha reportado un accidente trágico en la autopista\n Chamapa-Lechería, donde un camión cisterna se incendió tras un choque\n. "
                    "\nEl impacto del incidente provocó la muerte de uno de los ocupantes\n del camión y varios heridos fueron trasladados a hospitales cercanos.\n\n"
                    "Las autoridades están realizando una investigación exhaustiva\n para determinar la causa del accidente y tomar las medidas necesarias para mejorar la seguridad vial en la zona\n. "
                    "Este evento ha generado preocupaciones sobre la infraestructura vial y la seguridad en carreteras nacionales.\n", 
                    "Más Información", 
                    "Para actualizaciones continuas sobre accidentes y noticias relacionadas con el transporte, visita nuestra sección de noticias locales.");
                }
            }
        }
    }



        ventana.clear();
        // Dibujar el fondo para la ventana principal
        ventana.draw(spriteFondoPrincipal);
        ventana.draw(textoTitulo);
        ventana.draw(textoParrafo);
        ventana.draw(botonProgramas);
        ventana.draw(textoBotonProgramas);
        ventana.draw(botonAdmision);
        ventana.draw(textoBotonAdmision);
        ventana.draw(botonVinculacion);
        ventana.draw(textoBotonVinculacion);
        ventana.draw(botonServicios);
        ventana.draw(textoBotonServicios);
        ventana.draw(botonNoti);
        ventana.draw(textoBotonNoti);
        ventana.draw(botonAddress);
        ventana.draw(textoBotonAdress);
        ventana.draw(botonAbout);
        ventana.draw(textoBotonAbout);
        ventana.draw(imgSprite);
        ventana.display();
    }

    return 0;
}
