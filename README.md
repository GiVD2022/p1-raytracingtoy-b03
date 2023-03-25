# RayTracingToy
Pràctica 1 - GiVD 2022-23

## Taula de continguts:
* [Equip](#Equip)
* [Features](#Features)
* [Explicació de la pràctica](#Explicació)
* [Preguntes de la pràctica](#Preguntes)
* [Screenshots de cada fase](#Screenshots)


## Equip
**B03**
* Arturo Latorre
* Zijian Jiang
* Nil Torrelles
* Asier Augusto

## Features
- Fase 0
    - [x] Background amb degradat
        - Arturo + Zijian
    - [x] Color Shading
        - Arturo + Nil (Arreglat error menor, que donaba error amb la Box y el Triangle)
    - [x] Normal Shading
        - Arturo
    - [ ] Depth Shading
        - Estudiants que hi han participat
    - [x] Intersecció amb l'escena
        - Arturo
 - Fase 1
    - Creació de nous objectes i interseccions (VIRTUALWORLD) 
        - [x] Hit Box
            - Nil
        - [x] Hit Triangle
            - Zijian + Arturo + Nil (Arreglat el métode de Transformació -> AplicaTG)
        - [x] Hit Malla
            - Arturo + Zijian
 - Fase 2
    - [x] PAS 1
        - [x] Zijian
    - [x] PAS 2
        - [x] Blinn-Phong: Arturo + Zijian
        - [x] Phong: Arturo + Zijian
        - [x] Cel-Shading: Nil (In-Process)
    - [ ] PAS 3
        - [x] Blinn-PhongShadow: Asier + Arturo
        - [x] NormalShadow: Arturo
        - [x] PhongShadow: Arturo
        - [ ] CellShadow: Nil
        - [ ] ColorShadow: Arturo
        - [ ] Escena Complexa
    - [ ] PAS 4
        - [ ] RayTracer: 
        - [x] Metal: Arturo
    - [ ] PAS 5
        - Estudiants que hi han participat
        
- Parts opcionales: 
  - [x] Cilindres
    Nil (Cilindre sense tapes per una millor observació [Esta hueco], recomanat jugar amb els eixos de la Camara per apreciarlo)
   
  - [ ] Escena CSG 
  
  - [ ] Més d'una propietat en les dades reals
   
  - [ ] Mapeig de les dades reals en una esfera
  
    
    
## Explicació    
  * **Organització de la pràctica**
    * descriu com us heu organitzat
  
  * **Decisions a destacar**
    * Comenteu les decisions que heu pres 
    
## Preguntes
- Fase 0:
    - B) Quina escena es té carregada? Qui la crea? Quin setup té la classe? Des d’on es crea?
      - Resposta
    - C) Per què es veu aquest degradat? A quin mètode es calcula aquest color?
      - A RayTracer.
    - D) Quin efecte et trobes? Per què? Pots veure com ha arribat el flag de background al teu RayTracer? 
      - Resposta
    - E) En quina variable els trobes?
      - El color els trobes al vec3 color
    - F) I si volguessis canviar els colors del degradat? On els canviaries?
      - Si volguessis canviar els colors del degradat, hauries de canbiar el RGB = (0.5, 0.7, 1.0), pero tambe es pot fer que agafi els colors de la 
        paleta de colors, i es canvia a RayTracer.
    - G) Si prems Trace, no la veuràs, per què? 
      - Perque no esta calcular el hit, i has de modificar per a que en aquestos punts hi hagi un color que sera el del Shading.
    - H) Com hi pots accedir? A quina variable pots aconseguir l’estratègia a cridar? Com es crea aquesta estratègia des del menú?
      - Pots accedir-hi desde el setup, i agafant el color shading que tu volguis aplicar des del menu.
      - Ara mateix solament podem accedir a ColorShadow o ColorShading, pero mes endavant podrem a NormalShading y DepthShading.
      - Aquesta estrategia es crea des del menu que crida al builder, i alla crea el NormalShading del ShadingFactory.
    - I) Com faràs per a crear una nova estratègia de shading?
      - Per crear aquesta nova estrategia s'ha de habilitar el ui desde MainWindow, despres crear el metode en el builder que sera semblant al del
        ColorShading, pero creant NormalShading. Despres modificarem el ShadingFactory per aixi tenir el NormalShading. Y per ultim crearem la classe
        NormalShading (arxius cpp i hh) on cridarem la normal del HitInfo. 
    - J)  Com aconsegueixes que els colors estiguin normalitzats?
      - Resposta 
    - N) Per què veus només una esfera? On està situada a la teva escena? Amb quin radi? Per què? Per què és lila i no de color "kd": [0.7,0.6,0.5] com posa el
         fitxer?
      - Resposta
- Fase 1: 
    - 3A) Quan penses que es millor crear els triangles de la malla?
      - Just al tancar el fitxer, creas els triangles de la mesh, ja que estarà tot llegit
    - 
- Fase 2:
    - 1.2) On afegiries un atribut numSamples que defineixi el nombres de rajos per pixel i aixi controlar aquest fet?
      - Podriem afegir aquest atribut a la classe-> RayTracer com un int, així ens permetria controlar el nombre de raigs generats per a cada píxel.
    - 1.3) Es tracta de fer l'arrel quadrada de cada canal del color just abans de pintar-lo. On faras aquesta correcio?
      - Si es fa just abans de pintar, hauriem de fer la correció a la classe ColorShading.
    - 2.3) Què necessites canviar?
      - S'ha de canviar el metode de com calculem la difosa, ja que no utilitzarem el vector mig, sino el de reflexió.
    - 2.4) Necessites afegir informació en el material?
      -
    - 3.2) Quina component de la formula de Blinn-Phong s'haura de tenir en compte?
      -
    - 4.3) On hauries de llegir-la?
      -
    - 4.3) Per que si tens el MAX_DEPTH a 1, l'esfera no es veu transparent?
      -
    - 4.3) Com et canvia la visualització? Raona el perque?
      -
    - 4.3) Raona per què es veuen totes mes clares que les anteriors.
      -
      
    
    

## Screenshots
* **Fase 0**: 

* **Fase 1**: 

* **Fase 2**

    - Pas 2.2) Afegeix els teus resultats pas a pas en el README del teu projecte:
        - [Només component ambient](https://user-images.githubusercontent.com/72517965/227713663-9c22f466-4d90-4069-be9f-946b8517594e.png)
        - [Només component difosa](https://user-images.githubusercontent.com/72517965/227709908-b575eb86-2813-48f2-aa8e-d0429be96623.png)
        - [Només component especular](https://user-images.githubusercontent.com/72517965/227713128-3c4bc30d-501e-4c8c-a11e-aa94dfe97cc7.png)
        - [Les tres junts](https://user-images.githubusercontent.com/72517965/227713739-8f048ecb-c389-4a6f-9369-4e2f4e41f750.png)
        - [Atenuació amb profunditat](https://user-images.githubusercontent.com/72517965/227713760-31417e91-739f-42dd-b879-ed53d8d57d0e.png)
        - [Afegint ambient global](https://user-images.githubusercontent.com/72517965/227713854-62f4b88a-7946-4e36-832c-d02c1168f904.png)
    - Pas 2.3) Fes la captura final per a comparar-la amb el mètode de Blinn-Phong Shading:
        - [Només component ambient](https://user-images.githubusercontent.com/72517965/227714543-d42a4615-f2b6-4bb5-8955-dedae9724a28.png)
        - [Només component difosa](https://user-images.githubusercontent.com/72517965/227714550-514d8b1c-b12d-4591-902f-3047f753cab1.png)
        - [Només component especular](https://user-images.githubusercontent.com/72517965/227714553-b90d0471-0ab9-4ec0-b16d-f9ede8ab2b79.png)
        - [Captura Final](https://user-images.githubusercontent.com/72517965/227714565-fee5ba84-c185-453f-9fe7-6ebb679ae1a9.png)
    - Pas 2.4) Fes captures de pantalles amb els resultats obtinguts.
        - [Cell Shading]
    - Pas 3) Captures de les sombres
        - [BlinnPhongShadow](https://user-images.githubusercontent.com/72517965/227743991-4bfdd5d8-f223-464f-bb5f-12033be485e8.png)
        - [BlinnPhongShadow](https://user-images.githubusercontent.com/72517965/227744003-c6d7e68c-6c28-4269-afe5-7d1abb64e7fa.png)
        - [PhongShadow](https://user-images.githubusercontent.com/72517965/227744041-cc5e924f-8d61-4a1d-83cd-f2c419798590.png)
        - [PhongShadow](https://user-images.githubusercontent.com/72517965/227744055-6ebbf687-7344-43f0-a233-f54b3b6fe970.png)
        - [NormalShadow](https://user-images.githubusercontent.com/72517965/227745023-08092f8d-f3b1-4da8-bce1-4106fdd0720b.png)
        - [NormalShadow](https://user-images.githubusercontent.com/72517965/227745040-36e71f79-3ff0-4c79-a2c1-8cb0af31d3e0.png)







* **Opcionals**:


* **Més visualitzacions**:

   * Per totes les imatges, incluiu aqui la imatge obtinguda i els fitxers de dades i de configuració que heu fet servir
