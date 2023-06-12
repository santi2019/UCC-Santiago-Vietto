package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Socio;

@Repository
public class SocioImpDao extends GenericDaoImp<Socio, Long> implements SocioDao{

}
