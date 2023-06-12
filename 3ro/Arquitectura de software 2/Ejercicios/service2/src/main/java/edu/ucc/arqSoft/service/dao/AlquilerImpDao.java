package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Alquiler;

@Repository
public class AlquilerImpDao extends GenericDaoImp<Alquiler, Long> implements AlquilerDao {

}
