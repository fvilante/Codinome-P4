/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Matriz.h"
#include "Properties.h"

#include "catch.hpp"


TEST_CASE("Matriz class Test","[Matriz]") {
    
    Matriz m = Matriz();
    
    SECTION ("Testa setter e getters") {
        
        SECTION ("Testa PROPRIEDADES quanto a valores iniciais padrao") {
            
            TESTA_LER_PROPRIEDADE(DescricaoDoConector, "");
            TESTA_LER_PROPRIEDADE(FormatacaoDaImpressao, 0);
            TESTA_LER_PROPRIEDADE(LeituraDoCodigoDeBarras, "");
            TESTA_LER_PROPRIEDADE(TextoASerImpresso, "");
            TESTA_LER_PROPRIEDADE(CorDaTintaAImprimir, Cor::PRETO);
            TESTA_LER_PROPRIEDADE(FotoDoConector, ""); //endereço e nome do arquivo de imagem
            TESTA_LER_PROPRIEDADE(OffsetDeAvanco, 0);
            TESTA_LER_PROPRIEDADE(OffsetDeRetorno, 0);
            TESTA_LER_PROPRIEDADE(AlturaDoEixoZ, 0);
            TESTA_LER_PROPRIEDADE(Y1m, 0);
            TESTA_LER_PROPRIEDADE(Y2m, 0);
            TESTA_LER_PROPRIEDADE(X1m, 0);
            TESTA_LER_PROPRIEDADE(X2m, 0);

        }
        
        SECTION ("Testa PROPRIEDADES quanto a valores arbitrarios quaisquer") {
           
            TESTA_GRAVAR_E_LER_PROPRIEDADE(FormatacaoDaImpressao, 1);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(OffsetDeAvanco, -20);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(OffsetDeRetorno, +20);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(AlturaDoEixoZ, 50);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Y1m, 50);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Y2m, 500);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(X1m, 20);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(X2m, 450);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(CorDaTintaAImprimir, Cor::BRANCO);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(DescricaoDoConector, "P19238418923");
            TESTA_GRAVAR_E_LER_PROPRIEDADE(LeituraDoCodigoDeBarras, "M#1124121243-0");
            TESTA_GRAVAR_E_LER_PROPRIEDADE(TextoASerImpresso, "B14.22");
            TESTA_GRAVAR_E_LER_PROPRIEDADE(FotoDoConector, "/IMAGES/CONECTOR_P12214321.jpg");
        
        }

    }
    
}

