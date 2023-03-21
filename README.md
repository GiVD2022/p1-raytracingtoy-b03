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
        - Arturo
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
            - Zijian
        - [ ] Hit Malla
            - Estudiants que hi han participat
    - Creació de REAL DATA
        - [ ] FITTED PLANE: Pla de terra
            - Estudiants que hi han participat
        - [ ] Transformacions Translació i Escalat amb gizmos esferes
            - Estudiants que hi han participat
        - [ ] Gizmo de Box
            - Estudiants que hi han participat
        - [ ] Noves dades
            - Estudiants que hi han participat
       

- Parts opcionales: 
  - [ ] Cilindres
   
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


## Screenshots
* **Fase 0**: 

* **Fase 1**: 



* **Opcionals**:


* **Més visualitzacions**:

   * Per totes les imatges, incluiu aqui la imatge obtinguda i els fitxers de dades i de configuració que heu fet servir
