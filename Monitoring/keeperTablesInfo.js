//Хранитель типов блоков и функции, возвращающий названия таблиц определенного блока
var TYPE = {
    _GB : function(){
        return ["Температура устройства управления", "Питание устройства управления",
          "Температура синтезатора частот СЧ1", "Напряжение питания ИМС ФАПЧ Синтезатора СЧ1"];
    },

    _GKS : function(){
        return _GB();
    },


    _D1 : function(){
        return ["Напряжение U1 +12V", "Напряжение U2 +12V"];
    },

    _D2 : function(){
        return [];
    },
    _D3 : function(){
        return [];
    },


    _KU : function(){
        return [];
    },
    _KP : function(){
        return [];
    },


    _IVEP_100 : function(){
        return [];
    },
    _IVEP_PC : function(){
        return [];
    },


    _IVEP_D1 : function(){
        return [];
    },
    _IVEP_D23_D2 : function(){
        return [];
    },
    _IVEP_D23_D3 : function(){
        return [];
    },

    /*Испытания*/
    _BASI : function(){
        return ['Циклограмма', 'Исходные данные', 'Анализ'];
    },

    _BAPPD : function(){
        return ['Циклограмма', 'Исходные данные', 'Анализ'];
    },

}



function createArrayTables(typeString)
{
    switch(typeString) {
      case 'ГБ':
        return TYPE._GB();  //_ черта, чтобы компилятор не ругался на заглавную букву

      case 'ГКС':
        return TYPE._GKS();

      case 'Д1':
        return TYPE._D1();

      case 'БАСИ':
        return TYPE._BASI();

      case 'БАППД':
        return TYPE._BAPPD();

      default:
        return [];
    }
}


//Хранитель названия столбцов определенных типов таблиц
var TYPE_COLUMN = {
    _GB : function(){
        return [];
    },

    _GKS : function(){
        return _GB();
    },


    _D1 : function(){
        return ["Т начала дискрета \n(с)", "Т начала дискрета \n (мкс)", "U1 +12V", "U2 +12V"];
    },

    _D2 : function(){
        return [];
    },
    _D3 : function(){
        return [];
    },


    _KU : function(){
        return [];
    },
    _KP : function(){
        return [];
    },


    _IVEP_100 : function(){
        return [];
    },
    _IVEP_PC : function(){
        return [];
    },


    _IVEP_D1 : function(){
        return [];
    },
    _IVEP_D23_D2 : function(){
        return [];
    },
    _IVEP_D23_D3 : function(){
        return [];
    },

    /*Испытания*/
    _EQUIPMENT : function(){
        return ["IdChild", "Name", "Weight", "IdParent"];
    },

    _EMODE : function(){
        return ["Code", "Name", "Note"];
    },

    _TESTING : function(){
        return [];
    },

    _MOSCOW_TIME : function(){
        return [];
    },

    _REQUEST : function(){
        return [];
    },

    _TESTING_DATA : function(){
        return [];
    },

    _ONETIME_COMMANDS : function(){
        return [];
    },

    _SESSION : function(){
        return [];
    },

    _ANALYZE : function(){
        return [];
    },
}



function createArrayColumnsTable(typeString)
{
    switch(typeString) {
      case 'Блок Д1':
        return TYPE_COLUMN._D1(); //_ черта, чтобы компилятор не ругался на заглавную букву

      case 'Изделие':
        return TYPE_COLUMN._EQUIPMENT();

      case 'EMode':
        return TYPE_COLUMN._EMODE();

      default:
        return ["Undefined"];
    }
}




